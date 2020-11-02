#pragma once
#include<iostream>
using namespace std;
#include<string>
//职工的抽象类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获得岗位名称
	virtual string getDeptname() = 0;
	int m_ID;//职工编号	
	string m_Name;//职工姓名
	int m_DeptID;//职工所在部门编号
};