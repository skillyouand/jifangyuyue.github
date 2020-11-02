#pragma once
#include<iostream>
#include<map>
#include"全局文件添加.h"
#include<fstream>
using namespace std;
class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约记录
	void updateOrder();
	//记录容器： key-----记录的条数   value-----具体记录的键值对信息
	map<int, map<string, string>>m_orderData;
	//预约记录的条数
	int m_size;
};