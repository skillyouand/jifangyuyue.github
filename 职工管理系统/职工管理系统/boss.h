#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	//��������
	Boss(int ID, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ø�λ����
	virtual string getDeptname();
};