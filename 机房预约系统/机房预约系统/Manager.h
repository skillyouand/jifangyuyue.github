#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"ȫ���ļ����.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//��ʾ�˵�
	virtual void operMenu();
	//��ʾѧ����Ϣ���߽�ʦ��Ϣ
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearFile();
	//��ʼ������
	void initVector();
	//����Ƿ����ظ�
	bool CheckRepeat(int id,int type);
	//ѧ������
	vector<Student>s;
	//��ʦ����
	vector<Teacher>t;
	//��������Ϣ
	vector<ComputerRoom>Com;
};