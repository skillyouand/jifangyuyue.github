#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include"全局文件添加.h"
#include"orderFile.h"
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有人的预约
	void allOrder();
	//取消预约
	void  cancelOrder();
	//学生学号
	int m_ID;
	//存放机房的信息
	vector<ComputerRoom>com;
	
};