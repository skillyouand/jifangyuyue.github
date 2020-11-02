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
		//测试12名选手是否创建

		/*for_each(s.m_speaker.begin(), s.m_speaker.end(), myprint);
		for (map<int, Speaker>::iterator it = s.m_speaker.begin(); it != s.m_speaker.end(); it++)
		{
			cout << "选手的编号是：" << (*it).first << "\t" << (*it).second.m_name << "\t" << (*it).second.m_score[1] << endl;
		}*/
		cout << "请输入您的选择：" << endl;
		int d;
		cin >> d;
		switch (d)
		{
		case 1://开始演讲比赛
			s.StartSpeech();
			break;
		case 2://查看往届记录
			s.showsscore();
			break;
		case 3://清空比赛记录
			s.clearscore();
			break;
		case 0://退出比赛程序
			s.Exitsystem();
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}