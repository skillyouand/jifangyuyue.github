#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
//��ͨԱ����
class Employee :public Worker
{
public:
	//��������
	Employee(int id, string name, int deprtid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ø�λ����
	virtual string getDeptname();
};