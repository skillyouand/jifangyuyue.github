#include"Manager.h"
//Ĭ�Ϲ���
Manager::Manager()
{
	
}	
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա����Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;
	initVector();
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComID && ifs >> com.m_MaxNum)
	{
		Com.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << Com.size() << endl;
}
//��ʼ������
void Manager::initVector()
{
	s.clear();
	t.clear();
	ifstream ifs;
	//��ȡѧ���ļ��е���Ϣ
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}
	else
	{
		Student st;
		while (ifs >> st.m_ID && ifs >> st.m_Name && ifs >> st.m_Pwd)
		{
			s.push_back(st);
		}
		cout << "��ǰѧ��������Ϊ��" << s.size() << endl;
		ifs.close();
	}
	//��ȡ��ʦ�ļ��е���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}
	else
	{
		Teacher te;
		while (ifs >> te.m_empID && ifs >> te.m_Name && ifs >> te.m_Pwd)
		{
			t.push_back(te);
		}
		cout << "��ǰ��ʦ������Ϊ��" << t.size() << endl;
		ifs.close();
	}

}
//�鿴�Ƿ����ظ�
bool Manager::CheckRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = s.begin(); it != s.end(); it++)
		{
			if (id == it->m_ID)
			{
				return  1;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = t.begin(); it != t.end(); it++)
		{
			if (id == it->m_empID)
			{
				return 1;
			}
		}
	}
	return 0;
}
//��ʾ�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա  "<<this->m_Name<<"  ��¼��" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.����˺�          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.�鿴�˺�          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         3.�鿴����          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         4.���ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.ע����¼          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "����������ѡ��";
}
//����˺�
void Manager::addPerson()
{
	string ErrorTip;//�ظ�������ʾ
	string tip;//��ʾid��
	string filename;//�������ļ���
	ofstream ofs;
	while (1)
	{
		cout << "����������˺ŵ�����" << endl;
		cout << "1.���ѧ��" << endl;
		cout << "2.�����ʦ" << endl;
		
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//��ӵ���ѧ��
			filename = STUDENT_FILE;
			tip = "������ѧ����ѧ�ţ�";
			ErrorTip = "ѧ��ѧ���ظ�������������";
		}
		else if (select == 2)
		{	
			//��ӵ�����ʦ
			filename = TEACHER_FILE;
			tip = "�������ʦ��ְ���ţ�";
			ErrorTip = "��ʦְ�����ظ�������������";
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
		//����׷�ӵķ�ʽ д�ļ�
		ofs.open(filename, ios::out | ios::app);
		int id;
		string name;
		string pwd;
		cout << tip;
		cin >> id;
		bool ret = CheckRepeat(id, select);
		if (ret)//���ظ�
		{
			cout << ErrorTip << endl;
			system("pause");
			system("cls");
			break;
		}
		cout << "������������" << endl;
		cin >> name;
		cout << "���������룺" << endl;
		cin >> pwd;
		//���ļ����������
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "������ݳɹ�" << endl;
		this->initVector();
		system("pause");
		system("cls");
		ofs.close();
		break;
	}


	
	
}
//��ӡѧ����Ϣ
void print(Student &s)
{
	cout << "ѧ�ţ�" << s.m_ID << "\t" << "������" << s.m_Name << "\t" << "���룺" << s.m_Pwd << endl;
}
//��ӡ��ʦ��Ϣ
void prints(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_empID << "\t" << "������" << t.m_Name << "\t" << "���룺" << t.m_Pwd << endl;
}
//��ʾѧ����Ϣ���߽�ʦ��Ϣ
void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout <<"1.�鿴����ѧ����Ϣ" << endl;
	cout << "2.�鿴������ʦ��Ϣ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(s.begin(), s.end(), print);
	}
	else if (select == 2)
	{
		cout << "������ʦ����Ϣ���£�" << endl;
		for_each(t.begin(), t.end(), prints);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = Com.begin(); it != Com.end(); it++)
	{
		cout << "�����ı�ţ�" << it->m_ComID << "\t" << "����������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}