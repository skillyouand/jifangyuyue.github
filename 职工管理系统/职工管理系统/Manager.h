#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
//������
class Manger :public Worker
{
public:
	//��������
	Manger(int ID, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ø�λ����
	virtual string getDeptname();

};