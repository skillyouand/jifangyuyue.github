#include<iostream>
#include"speechManager.h"
#include<string>
using namespace std;

//void myprint(map<int,Speaker>::reference i)
//{
//	cout << i.first << "\t" << i.second.m_name << "\t" << i.second.m_score[0] << endl;
//}

int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager s;
	while (1)
	{
		s.Show_Menu();
		//����12��ѡ���Ƿ񴴽�

		/*for_each(s.m_speaker.begin(), s.m_speaker.end(), myprint);
		for (map<int, Speaker>::iterator it = s.m_speaker.begin(); it != s.m_speaker.end(); it++)
		{
			cout << "ѡ�ֵı���ǣ�" << (*it).first << "\t" << (*it).second.m_name << "\t" << (*it).second.m_score[1] << endl;
		}*/
		cout << "����������ѡ��" << endl;
		int d;
		cin >> d;
		switch (d)
		{
		case 1://��ʼ�ݽ�����
			s.StartSpeech();
			break;
		case 2://�鿴�����¼
			s.showsscore();
			break;
		case 3://��ձ�����¼
			s.clearscore();
			break;
		case 0://�˳���������
			s.Exitsystem();
			break;
		default:
			cout << "�������,����������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}