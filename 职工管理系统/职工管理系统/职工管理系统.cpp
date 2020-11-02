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
	//对三个不同职工的调用，检查程序是否出错
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;
	Worker* worker1 = NULL;
	worker1 = new Manger(1,"李四",2);
	worker1->showInfo();
	delete worker1;
	Worker* worker3 = NULL;
	worker3 = new Boss(1, "王五", 3);
	worker3->showInfo();
	delete worker3;*/
	WorkerManher wm;
	while(1)
	{
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitsystem();
			break;
		case 1://添加职工
			wm.add_Emp();
			break;
		case 2://显示职工
			wm.show_emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_EMp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
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