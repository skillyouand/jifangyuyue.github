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
	//���캯��	
	WorkerManher();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void exitsystem();
	//���ְ��
	void add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	//ͳ���ļ��г�Ա������
	int get_num();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾԱ��
	void show_emp();
	//ְ������ָ��
	Worker** m_emp;
	//��¼��ǰְ������
	int Emp_array;
	//���ձ���ж�Ա���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);
	//ɾ��Ա��
	void Del_Emp();
	//�޸�Ա��
	void Mod_Emp(); 
	//����ְ��
	void Find_EMp();
	//����
	void Sort_Emp();
	//ɾ����·
	void Clean_Emp();
	//��������
	~WorkerManher();
};