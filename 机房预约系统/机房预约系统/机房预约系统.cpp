#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"ȫ���ļ����.h"
#include"student.h"
#include"teacher.h"
#include"Manager.h"
//�����ʦ���Ӳ˵�����
void TeacherMenu(Identity*& teacher)
{
	while (1)
	{
		//������ʦ���Ӳ˵�
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		char select;
		cin >> select;
		if (select =='1')//�鿴����ԤԼ
		{
			tea->showAllorder();
		}
		else if (select == '2')//���ԤԼ
		{
			tea->validOrder();
		}
		else if (select == '0')//ע����¼
		{
			delete teacher;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else//�����������������
		{
			cout<< "�����������������" << endl;
		}
	}
}
//����ѧ�����Ӳ˵�����
void StudentMenu(Identity*& student)
{
	while (1)
	{
		//����ѧ�����Ӳ˵�
		student->operMenu();
		//�������ָ��ת�������ָ�룬���������е������ӿ�
		Student* a = (Student*)student;
		//�����û���ѡ��
		char select;
		cin >> select;
		if (select == '1')//����ԤԼ
		{
			a->applyOrder();
		}
		else if (select == '2')//�鿴����ԤԼ
		{
			a->showMyOrder();
		}
		else if (select == '3')//�鿴�����˵�ԤԼ
		{
			a->allOrder();
		}
		else if (select == '4')//ȡ��ԤԼ
		{
			a->cancelOrder();
		}
		else if (select == '0')//ע����¼
		{
			delete student;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else//�����������������
		{
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
		}

	}
}
//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager)//�ø����ָ��ָ��֮���������ã���̬��ʹ�ã�
{

	while (1)
	{	
		//���ù���Ա���Ӳ˵�
		manager->operMenu();
		//�������ָ��ת�������ָ�룬����������������ӿ�
		Manager* man = (Manager*)manager;
		 char select;
		//�����û���ѡ��
		cin >> select;
		switch (select)
		{
		case '1'://����˺�
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case '2'://�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case '3'://�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case '4'://���ԤԼ
			cout << "���ԤԼ" << endl;
			man->clearFile();
			break;
		case '0'://ע���˺�
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//��¼����  ����1 �����ļ��� ����2 �����������
void LoginIn(string filename, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(filename,ios::in);
	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ�����
	{
		
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if(type==2)
	{
		cout << "����������ְ����ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fid;//���ļ��л�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fName && ifs >> fPwd)
		{
			
			if (id == fid && name == fName && pwd == fPwd)
			{
				cout << "ѧ�������֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fid;//���ļ��л�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fName && ifs >> fPwd)
		{
			
			if (id == fid && name == fName && pwd == fPwd)
			{
				cout << "��ʦ�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if(type==3)
	{
		//����Ա�����֤
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs >> fName && ifs >> fPwd)
		{
			if ( name == fName && pwd == fPwd)
			{
				cout << "����Ա�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ��" << endl;
	system("pause");
	system("cls");
}
int main()
{
	char select;
	while (1)
	{
		cout << "----------------- ��ӭ����ֱ����ý����ԤԼϵͳ ------------------" << endl;
		cout << "\t\t-------------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         1.ѧ������          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2.��    ʦ          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3.�� �� Ա          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0.��    ��          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t-------------------------------\n";
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case '1'://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case '2'://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case '3'://����Ա���
			LoginIn(MANAGER_FILE, 3);
			break;
		case '0'://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default://�������
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}