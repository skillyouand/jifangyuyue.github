#include<iostream>
using namespace std;
#include"workerManger.h"
#include"worker.h"
#include"employee.h"
#include"Manager.h"
#include"boss.h"
#include<string>
int main()
{
	//��������ְͬ���ĵ��ã��������Ƿ����
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;
	Worker* worker1 = NULL;
	worker1 = new Manger(1,"����",2);
	worker1->showInfo();
	delete worker1;
	Worker* worker3 = NULL;
	worker3 = new Boss(1, "����", 3);
	worker3->showInfo();
	delete worker3;*/
	WorkerManher wm;
	while(1)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitsystem();
			break;
		case 1://���ְ��
			wm.add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_EMp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}