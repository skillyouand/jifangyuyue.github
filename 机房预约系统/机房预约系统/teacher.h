#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int mepID, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllorder();
	//���ԤԼ
	void validOrder();
	//��ʦְ�����
	int m_empID;
};
