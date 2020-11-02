#include"speechManager.h"
//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载往届记录
	this->loadscore();
}
//显示菜单
void SpeechManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "*********欢迎参加演讲比赛*********" << endl;
	cout << "**********1.开始演讲比赛**********" << endl; 
	cout << "**********2.查看往届记录********** "<< endl;
	cout << "**********3.清空比赛记录**********" << endl;
	cout << "**********0.退出比赛流程**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//初始化容器和属性
void SpeechManager::initSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_speaker.clear();
	//初始化比赛轮数
	this->m_Index = 1;
	//将记录的容器清空
	this->m_Record.clear();
}
//创建12名选手
void SpeechManager::createSpeaker()
{
	string namespeed = "ABCDEFGHIJKL";
	for (int i = 0; i < namespeed.size(); i++)
	{
		string name = "选手";
		name += namespeed[i];
		//创建具体选手
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//创建选手编号，并放入到v1容器中
		this->v1.push_back(1001 + i);
		//选手编号以及对应的选手,放到MAP容器当中
		this->m_speaker.insert(make_pair(i + 1001, sp));

	}
}
//开始比赛
void  SpeechManager::StartSpeech()
{
	//第一轮比赛
	//1.抽签
	this->chouqian();
	//2.比赛
	this->speechContest();
	//3.显示晋级结束
	this->showScore();
	//第二轮比赛开始
	this->m_Index++;
	//1.抽签
	this->chouqian();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showScore();
	//4.保存分数
	this->savescore();


	//重置比赛，获取记录
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载往届记录
	this->loadscore();
	cout << "本届比赛结束" << endl;
	system("pause");
	system("cls");
	
}
//抽签
void SpeechManager::chouqian()
{

	cout << "第<<" << this->m_Index << " >>轮比赛开始" << endl;
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
//比赛
void SpeechManager::speechContest()
{
	//临时容器
	multimap<double, int, greater<double>>groupScore;//保存key分数，value选手编号，并按照分数进行降序排列
	cout << "---------------第<<" << this->m_Index << "轮比赛正式开始----------------" << endl;
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
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//排序
		//去掉最高分去掉最低分
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);//求和
		double ave = sum / (double)d.size();//求平均值
		////测试（打印输出平均值：）
		//cout << "编号：" << *it << "选手：" << this->m_speaker[*it].m_name << "获取的平均分为：" << ave << endl;
		//将获得的分数放入map容器中的score
		this->m_speaker[*it].m_score[this->m_Index - 1] = ave;
		//6个人一组，用临时容器保存
		groupScore.insert(pair<double, int>(ave, *it));
		if (num % 6 == 0)
		{
			cout << "第 " << (num / 6) << " 小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator m = groupScore.begin(); m != groupScore.end(); m++)
			{
				cout << "编号：" << m->second << "\t" << "姓名：" << this->m_speaker[m->second].m_name
					<< "\t" << "成绩：" << this->m_speaker[m->second].m_score[this->m_Index - 1] << endl;
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
	cout << "---------------第 " << this->m_Index << " 轮比赛结束---------------" << endl;
	cout << endl;
	system("pause");
}
//保存分数记录
void SpeechManager::savescore()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << ","<<this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	//关闭文件
	ofs.close();
	cout << "文件已保存" << endl;
	//有了文件，文件不为空
	this->fileIsEmpty = 0;
}
//读取记录
void SpeechManager::loadscore()
{
	ifstream ifs("speech.csv", ios::in);//读文件
	if (!ifs.is_open())//判断文件是否存在
	{
		this->fileIsEmpty = 1;
		//cout << "打开文件失败" << endl;
		ifs.close();
		return;
	}
	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = 1;
		//cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = 0;
	ifs.putback(ch);//将上面读走的单个字符ch都回来，防止缺失
	string date;
	int index = 1;
	while (ifs >> date)
	{	
		vector<string>v;//存放获得的字符串
		//cout << date;
		int pos;
		int start = 0;
		while (1)
		{
			pos = date.find(",",start);//加start很有必要，从start开始向后查询！！！！！！！不加的话程序会有问题 
			if (pos == -1)
			{
				//没有找到
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
			cout << "----------------------第 " << it->first << " 届--------------------------" << endl;
			cout <<"冠军编号：" << it->second[0] << "\t分数:" << it->second[1] << endl;
			cout <<"亚军编号：" << it->second[2] << "\t分数:" << it->second[3] << endl;
			cout <<"季军编号：" << it->second[4] << "\t分数:" << it->second[5] << endl;
		}*/
		index++;
	}
	ifs.close();
}
//显示往届得分
void SpeechManager::showsscore()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
		{
			cout << "----------------------第 " << it->first << " 届--------------------------" << endl;
			cout << "冠军编号：" << it->second[0] << "\t分数:" << it->second[1] << endl;
			cout << "亚军编号：" << it->second[2] << "\t分数:" << it->second[3] << endl;
			cout << "季军编号：" << it->second[4] << "\t分数:" << it->second[5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//显示比赛结束
void SpeechManager::showScore()
{
	vector<int>V;
	cout << "---------------第 " << this->m_Index << " 轮晋级选手信息如下：---------------" << endl;
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
		cout << "编号：" << *it << "\t" << "姓名：" << m_speaker[*it].m_name
			<< "\t" << "成绩：" << m_speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->Show_Menu();
}
//清空往届记录
void SpeechManager::clearscore()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//加载往届记录
		this->loadscore();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
//退出系统
void SpeechManager::Exitsystem()
{
	cout << "欢迎下次使用演讲比赛程序" << endl;
	system("pause");
	exit(0);
}
//析构函数
SpeechManager::~SpeechManager()
{

}
