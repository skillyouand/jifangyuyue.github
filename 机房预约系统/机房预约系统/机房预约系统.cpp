#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"全局文件添加.h"
#include"student.h"
#include"teacher.h"
#include"Manager.h"
//进入教师的子菜单界面
void TeacherMenu(Identity*& teacher)
{
	while (1)
	{
		//调用老师的子菜单
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		char select;
		cin >> select;
		if (select =='1')//查看所有预约
		{
			tea->showAllorder();
		}
		else if (select == '2')//审核预约
		{
			tea->validOrder();
		}
		else if (select == '0')//注销登录
		{
			delete teacher;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else//输入错误，请重新输入
		{
			cout<< "输入错误请重新输入" << endl;
		}
	}
}
//进入学生的子菜单界面
void StudentMenu(Identity*& student)
{
	while (1)
	{
		//调用学生的子菜单
		student->operMenu();
		//将父类的指针转回子类的指针，调用子类中的其他接口
		Student* a = (Student*)student;
		//接受用户的选择
		char select;
		cin >> select;
		if (select == '1')//申请预约
		{
			a->applyOrder();
		}
		else if (select == '2')//查看自身预约
		{
			a->showMyOrder();
		}
		else if (select == '3')//查看所有人的预约
		{
			a->allOrder();
		}
		else if (select == '4')//取消预约
		{
			a->cancelOrder();
		}
		else if (select == '0')//注销登录
		{
			delete student;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else//输入错误，请重新输入
		{
			cout << "输入错误，请重新选择" << endl;
			system("pause");
			system("cls");
		}

	}
}
//进入管理员的子菜单界面
void managerMenu(Identity*& manager)//用父类的指针指向之类对象的引用（多态的使用）
{

	while (1)
	{	
		//调用管理员的子菜单
		manager->operMenu();
		//将父类的指针转回子类的指针，调用子类里的其他接口
		Manager* man = (Manager*)manager;
		 char select;
		//接收用户的选择
		cin >> select;
		switch (select)
		{
		case '1'://添加账号
			cout << "添加账号" << endl;
			man->addPerson();
			break;
		case '2'://查看账号
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case '3'://查看机房
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case '4'://清空预约
			cout << "清空预约" << endl;
			man->clearFile();
			break;
		case '0'://注销账号
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//登录功能  参数1 操作文件名 参数2 操作身份类型
void LoginIn(string filename, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(filename,ios::in);
	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生身份
	{
		
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if(type==2)
	{
		cout << "请输入您的职工标号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fid;//从文件中获取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fName && ifs >> fPwd)
		{
			
			if (id == fid && name == fName && pwd == fPwd)
			{
				cout << "学生身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fid;//从文件中获取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fName && ifs >> fPwd)
		{
			
			if (id == fid && name == fName && pwd == fPwd)
			{
				cout << "教师身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				TeacherMenu(person);
				return;
			}
		}
	}
	else if(type==3)
	{
		//管理员身份验证
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if ( name == fName && pwd == fPwd)
			{
				cout << "管理员身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");
}
int main()
{
	char select;
	while (1)
	{
		cout << "----------------- 欢迎来到直播传媒机房预约系统 ------------------" << endl;
		cout << "\t\t-------------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         1.学生代表          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2.老    师          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3.管 理 员          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0.退    出          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t-------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case '1'://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case '2'://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case '3'://管理员身份
			LoginIn(MANAGER_FILE, 3);
			break;
		case '0'://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default://输入错误
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}