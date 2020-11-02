#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	//析构函数
	Boss(int ID, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获得岗位名称
	virtual string getDeptname();
};