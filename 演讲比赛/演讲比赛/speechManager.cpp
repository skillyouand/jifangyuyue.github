#include"speechManager.h"
//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//���������¼
	this->loadscore();
}
//��ʾ�˵�
void SpeechManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "*********��ӭ�μ��ݽ�����*********" << endl;
	cout << "**********1.��ʼ�ݽ�����**********" << endl; 
	cout << "**********2.�鿴�����¼********** "<< endl;
	cout << "**********3.��ձ�����¼**********" << endl;
	cout << "**********0.�˳���������**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//��ʼ������������
void SpeechManager::initSpeech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
	//����¼���������
	this->m_Record.clear();
}
//����12��ѡ��
void SpeechManager::createSpeaker()
{
	string namespeed = "ABCDEFGHIJKL";
	for (int i = 0; i < namespeed.size(); i++)
	{
		string name = "ѡ��";
		name += namespeed[i];
		//��������ѡ��
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//����ѡ�ֱ�ţ������뵽v1������
		this->v1.push_back(1001 + i);
		//ѡ�ֱ���Լ���Ӧ��ѡ��,�ŵ�MAP��������
		this->m_speaker.insert(make_pair(i + 1001, sp));

	}
}
//��ʼ����
void  SpeechManager::StartSpeech()
{
	//��һ�ֱ���
	//1.��ǩ
	this->chouqian();
	//2.����
	this->speechContest();
	//3.��ʾ��������
	this->showScore();
	//�ڶ��ֱ�����ʼ
	this->m_Index++;
	//1.��ǩ
	this->chouqian();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();
	//4.�������
	this->savescore();


	//���ñ�������ȡ��¼
	//��ʼ������������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//���������¼
	this->loadscore();
	cout << "�����������" << endl;
	system("pause");
	system("cls");
	
}
//��ǩ
void SpeechManager::chouqian()
{

	cout << "��<<" << this->m_Index << " >>�ֱ�����ʼ" << endl;
	cout << "----------------------------------------------" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
	system("pause");
}
//����
void SpeechManager::speechContest()
{
	//��ʱ����
	multimap<double, int, greater<double>>groupScore;//����key������valueѡ�ֱ�ţ������շ������н�������
	cout << "---------------��<<" << this->m_Index << "�ֱ�����ʽ��ʼ----------------" << endl;
	vector<int>v_src;
	int num = 0;
	if (this->m_Index == 1)
	{
		v_src = this->v1;
	}
	else
	{
		v_src = this->v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//����
		//ȥ����߷�ȥ����ͷ�
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);//���
		double ave = sum / (double)d.size();//��ƽ��ֵ
		////���ԣ���ӡ���ƽ��ֵ����
		//cout << "��ţ�" << *it << "ѡ�֣�" << this->m_speaker[*it].m_name << "��ȡ��ƽ����Ϊ��" << ave << endl;
		//����õķ�������map�����е�score
		this->m_speaker[*it].m_score[this->m_Index - 1] = ave;
		//6����һ�飬����ʱ��������
		groupScore.insert(pair<double, int>(ave, *it));
		if (num % 6 == 0)
		{
			cout << "�� " << (num / 6) << " С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator m = groupScore.begin(); m != groupScore.end(); m++)
			{
				cout << "��ţ�" << m->second << "\t" << "������" << this->m_speaker[m->second].m_name
					<< "\t" << "�ɼ���" << this->m_speaker[m->second].m_score[this->m_Index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					v3.push_back(it->second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "---------------�� " << this->m_Index << " �ֱ�������---------------" << endl;
	cout << endl;
	system("pause");
}
//���������¼
void SpeechManager::savescore()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ","<<this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	//�ر��ļ�
	ofs.close();
	cout << "�ļ��ѱ���" << endl;
	//�����ļ����ļ���Ϊ��
	this->fileIsEmpty = 0;
}
//��ȡ��¼
void SpeechManager::loadscore()
{
	ifstream ifs("speech.csv", ios::in);//���ļ�
	if (!ifs.is_open())//�ж��ļ��Ƿ����
	{
		this->fileIsEmpty = 1;
		//cout << "���ļ�ʧ��" << endl;
		ifs.close();
		return;
	}
	//�ж��ļ��Ƿ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = 1;
		//cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = 0;
	ifs.putback(ch);//��������ߵĵ����ַ�ch����������ֹȱʧ
	string date;
	int index = 1;
	while (ifs >> date)
	{	
		vector<string>v;//��Ż�õ��ַ���
		//cout << date;
		int pos;
		int start = 0;
		while (1)
		{
			pos = date.find(",",start);//��start���б�Ҫ����start��ʼ����ѯ�����������������ӵĻ������������ 
			if (pos == -1)
			{
				//û���ҵ�
				break;
			}
			string str = date.substr(start, pos - start);
			//cout << str << endl;
			v.push_back(str);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
		{
			cout << "----------------------�� " << it->first << " ��--------------------------" << endl;
			cout <<"�ھ���ţ�" << it->second[0] << "\t����:" << it->second[1] << endl;
			cout <<"�Ǿ���ţ�" << it->second[2] << "\t����:" << it->second[3] << endl;
			cout <<"������ţ�" << it->second[4] << "\t����:" << it->second[5] << endl;
		}*/
		index++;
	}
	ifs.close();
}
//��ʾ����÷�
void SpeechManager::showsscore()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
		{
			cout << "----------------------�� " << it->first << " ��--------------------------" << endl;
			cout << "�ھ���ţ�" << it->second[0] << "\t����:" << it->second[1] << endl;
			cout << "�Ǿ���ţ�" << it->second[2] << "\t����:" << it->second[3] << endl;
			cout << "������ţ�" << it->second[4] << "\t����:" << it->second[5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//��ʾ��������
void SpeechManager::showScore()
{
	vector<int>V;
	cout << "---------------�� " << this->m_Index << " �ֽ���ѡ����Ϣ���£�---------------" << endl;
	if (this->m_Index == 1)
	{
		V = v2;
	}
	else
	{
		V = v3;
	}
	for (vector<int>::iterator it = V.begin(); it != V.end(); it++)
	{
		cout << "��ţ�" << *it << "\t" << "������" << m_speaker[*it].m_name
			<< "\t" << "�ɼ���" << m_speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->Show_Menu();
}
//��������¼
void SpeechManager::clearscore()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//���������¼
		this->loadscore();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//�˳�ϵͳ
void SpeechManager::Exitsystem()
{
	cout << "��ӭ�´�ʹ���ݽ���������" << endl;
	system("pause");
	exit(0);
}
//��������
SpeechManager::~SpeechManager()
{

}
