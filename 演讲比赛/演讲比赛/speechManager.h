#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<ctime>
#include<numeric>
#include<fstream>
using namespace std;
class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//显示菜单
	void Show_Menu();
	//初始化容器和属性
	void initSpeech();
	//创建12名选手
	void createSpeaker();
	//开始比赛
	void StartSpeech();
	//抽签
	void chouqian();
	//比赛
	void speechContest();
	//保存分数记录
	void savescore();
	//读取记录
	void loadscore();
	//显示往届得分
	void showsscore();
	//清空往届记录
	void clearscore();
	//显示比赛结束
	void showScore();
	//退出演讲比赛系统
	void Exitsystem();
	//析构函数
	~SpeechManager();
	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;
	//第一轮晋级选手编号容器
	vector<int>v2;
	//胜出前三名选手容器编号
	vector<int>v3;
	//存放便哈以及对应的具体选手容器
	map<int, Speaker>m_speaker;
	//存放比赛的轮数
	int m_Index;
	//判断文件是否为空的标志
	bool fileIsEmpty = 0;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
};