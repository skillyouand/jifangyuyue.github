#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int mepID, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllorder();
	//审核预约
	void validOrder();
	//教师职工编号
	int m_empID;
};
