#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include"ȫ���ļ����.h"
#include"orderFile.h"
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴�����˵�ԤԼ
	void allOrder();
	//ȡ��ԤԼ
	void  cancelOrder();
	//ѧ��ѧ��
	int m_ID;
	//��Ż�������Ϣ
	vector<ComputerRoom>com;
	
};