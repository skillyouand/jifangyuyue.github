#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"全局文件添加.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//显示菜单
	virtual void operMenu();
	//显示学生信息或者教师信息
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearFile();
	//初始化容器
	void initVector();
	//检查是否有重复
	bool CheckRepeat(int id,int type);
	//学生容器
	vector<Student>s;
	//老师容器
	vector<Teacher>t;
	//机房的信息
	vector<ComputerRoom>Com;
};