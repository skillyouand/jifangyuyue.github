#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>
//��5��ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ͷ֣�ȡƽ��ֵ
//��������ѡ�ַŵ�vector��
//����vector������ȡ��ÿ��ѡ�֣�ִ��forѭ�����԰�10�����ִ��deque������
//sort�㷨��deque�����з�������ȥ����߷ֺ���ͷ�
//deque�����������ۼ��ܷ�
//��ȡƽ��ֵ
class Player
{
public:
	Player(string name, float score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	float m_score;
};
void createplayer(vector<Player>& p)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		int score = 0;
		Player a(name, score);
		//��������player�������������
		p.push_back(a);
	}
}
//���
void setscore(vector<Player>& p)
{
	for (vector<Player>::iterator it = p.begin(); it != p.end(); it++)
	{
		deque<float>d;
		for (int i = 0; i < 10; i++)
		{
			float score = rand() % 41+ 60;//60-100��
			d.push_back(score);
		}
		cout << it->m_name << "  ����Ϊ��" << endl;
		for (deque<float>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());//˳���С��������
		d.pop_front();//ȥ����ͷ�
		d.pop_back();//ȥ����߷�
		//��ȡƽ����
		float sum = 0;
		for (deque<float>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//�ۼ�ÿ����ί�ķ���
		}
		float average = sum / d.size();
		//��ƽ���ַŵ�������
		it->m_score = average;
		//ѡ�����÷�
		cout << "����ƽ����Ϊ��" << endl;
		cout<<it->m_score << endl;
		
	}
	
}
int main()
{	
	//���������
	srand((unsigned int)time(NULL));
	vector<Player>p;//���ѡ�ֵ�����
	createplayer(p);
	//����
	//for (vector<Player>::iterator it = p.begin(); it!=p.end(); it++)
	//{
	//	cout << "������"<<(*it).m_name << "  ������"<< it->m_score<< endl;
	//}
	//2.��5��ѡ�ִ��
	setscore(p);
	//3.��ʾ���÷�
	system("pasue");
	return 0;
}