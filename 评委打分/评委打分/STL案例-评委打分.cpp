#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>
//有5名选手ABCDE，10个评委分别对每一个选手打分，去掉最高分，去掉最低分，取平均值
//创建五名选手放到vector中
//遍历vector容器，取出每个选手，执行for循环可以把10个评分大道deque容器中
//sort算法对deque容器中分数排序，去除最高分和最低分
//deque容器遍历，累加总分
//获取平均值
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
		string name = "选手";
		name += nameseed[i];
		int score = 0;
		Player a(name, score);
		//将创建的player对象放入容器中
		p.push_back(a);
	}
}
//打分
void setscore(vector<Player>& p)
{
	for (vector<Player>::iterator it = p.begin(); it != p.end(); it++)
	{
		deque<float>d;
		for (int i = 0; i < 10; i++)
		{
			float score = rand() % 41+ 60;//60-100分
			d.push_back(score);
		}
		cout << it->m_name << "  分数为：" << endl;
		for (deque<float>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());//顺序从小到大排序
		d.pop_front();//去掉最低分
		d.pop_back();//去掉最高分
		//获取平均分
		float sum = 0;
		for (deque<float>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//累加每个评委的分数
		}
		float average = sum / d.size();
		//将平均分放到人身上
		it->m_score = average;
		//选手最后得分
		cout << "最后的平均分为：" << endl;
		cout<<it->m_score << endl;
		
	}
	
}
int main()
{	
	//随机数种子
	srand((unsigned int)time(NULL));
	vector<Player>p;//存放选手的容器
	createplayer(p);
	//测试
	//for (vector<Player>::iterator it = p.begin(); it!=p.end(); it++)
	//{
	//	cout << "姓名："<<(*it).m_name << "  分数："<< it->m_score<< endl;
	//}
	//2.给5名选手打分
	setscore(p);
	//3.显示最后得分
	system("pasue");
	return 0;
}