#pragma once
#include<iostream>
using namespace std;
#include<string>
//ְ���ĳ�����
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ø�λ����
	virtual string getDeptname() = 0;
	int m_ID;//ְ�����	
	string m_Name;//ְ������
	int m_DeptID;//ְ�����ڲ��ű��
};