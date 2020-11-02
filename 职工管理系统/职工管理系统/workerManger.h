#pragma once
#include<iostream>
#include"worker.h"
#include"boss.h"
#include"Manager.h"
#include"employee.h"
#include<fstream>
using namespace std;
#define FILENAME "empFile.txt"

class WorkerManher
{
public:
	//构造函数	
	WorkerManher();
	//展示菜单
	void Show_Menu();
	//退出系统
	void exitsystem();
	//添加职工
	void add_Emp();
	//保存文件
	void save();
	//判断文件是否为空的标志
	bool m_FileIsEmpty;
	//统计文件中成员的人数
	int get_num();
	//初始化员工
	void init_Emp();
	//显示员工
	void show_emp();
	//职工数组指针
	Worker** m_emp;
	//记录当前职工人数
	int Emp_array;
	//按照编号判断员工是否存在，若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);
	//删除员工
	void Del_Emp();
	//修改员工
	void Mod_Emp(); 
	//查找职工
	void Find_EMp();
	//排序
	void Sort_Emp();
	//删库跑路
	void Clean_Emp();
	//析构函数
	~WorkerManher();
};