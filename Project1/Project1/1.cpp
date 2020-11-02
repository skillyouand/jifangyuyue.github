#include<iostream>
using namespace std;
#include<string>
#define max 1000
//设计联系人的结构体
struct lianxiren
{
	//联系人上限为1000，联系人的信息（姓名，性别，年龄，联系电话，家庭住址）
	//姓名
	string l_name;
	//性别 1.男 2.女
	int l_sex;
	//年龄
	int l_age;
	//电话
	string l_phone;
	//住址
	string l_addr;
};
//设计通信录的结构
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct lianxiren A_people[max];
	//通讯录中当前记录联系人数
	int A_size;
};
void showMenu()//创建界面
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通信录  *****" << endl;
	cout << "**************************" << endl;
}
void addlxr(Addressbooks *abs)//添加联系人
{
	//判断通讯录是否满了
	if (abs->A_size == max)
	{
		cout << "通讯录满了，无法添加" << endl;
		return;
	}
	else
	{
		//添加联系人
		//姓名
		string name;
		cout << "输入联系人姓名" << endl;
		cin >> name;
		abs->A_people[abs->A_size].l_name= name;
		//性别
		int sex;
		cout << "输入联系人的性别" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		while (1) //如果输入1或2可以退循环
			//如果输入有误则退出循环
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->A_people[abs->A_size].l_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		int age;
		cout << "请输入联系人年龄" << endl;
		cin >> age;
		abs->A_people[abs->A_size].l_age = age;
		//电话
		string phone;
		cout << "请输入联系人电话" << endl;
		cin >> phone;
		abs->A_people[abs->A_size].l_phone = phone;
		//住址
		string address;
		cout << "请输入联系人的住址" << endl;
		cin >> address;
		abs->A_people[abs->A_size].l_addr = address;
		//更新通讯录人数
		abs->A_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showperson(Addressbooks *abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人
	if (abs->A_size == 0)
	{
		cout << "通讯录中现在还没有联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->A_size; i++)
		{
			cout << "姓名:" << abs->A_people[i].l_name << "\t";
			cout << "年龄:" << abs->A_people[i].l_age << "\t";
			cout << "性别:" <<(abs->A_people[i].l_sex == 1?"男":"女")<< "\t";
			cout << "电话:"<< abs->A_people[i].l_phone << "\t";
			cout << "地址:" << abs->A_people[i].l_addr << endl;
		}
		
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，如果存在返回联系人所在的具体位置，不存在则返回-1
int isexist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->A_size; i++)
	{
		//找到用户输入的姓名
		if (abs->A_people[i].l_name == name)
		{
			return i;
		}
		
	}
	return -1;
}
//删除指定联系人
void shanchulxr(Addressbooks *abs)
{
	cout << "请输入删除的联系人姓名:" << endl;
	string name;
	cin >> name;
	int a = isexist(abs, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = a; i < abs->A_size; i++)
		{
			//数据前移
			abs->A_people[i] = abs->A_people[i + 1];
		}
		abs->A_size--;//更新通讯录中成员人数
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找指定联系人信息
void findperson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int a=isexist(abs, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名：" << abs->A_people[a].l_name << "\t";
		cout << "性别：" << (abs->A_people[a].l_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->A_people[a].l_age << "\t";
		cout << "电话：" << abs->A_people[a].l_phone << "\t";
		cout << "地址：" << abs->A_people[a].l_addr << endl;
	}
	system("pause");
	system("cls");
}
//修改指定的联系人信息
void modifyperson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人信息" << endl;
	string name;
	cin >> name;
	int a=isexist(abs, name);
	if (a == -1)
	{
		cout << "没有找到要修改的联系人" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->A_people[a].l_name = name;
		int sex;
		cout << "请输入性别：" <<endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while(1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->A_people[a].l_sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;

			}
			
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->A_people[a].l_age = age;
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->A_people[a].l_phone = phone;
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->A_people[a].l_addr = address;
		cout << "修改成功" << endl;
		cout << "姓名：" << abs->A_people[a].l_name << "\t";
		cout << "性别：" << (abs->A_people[a].l_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->A_people[a].l_age << "\t";
		cout << "电话：" << abs->A_people[a].l_phone << "\t";
		cout << "地址：" << abs->A_people[a].l_addr << endl;
		system("pause");
		system("cls");
	}
}
//清空联系人
void clearall(Addressbooks *abs)
{
	//将当前记录的联系人数量变为0，做一个逻辑上的清空
	cout << "确定是否要全部清空" << endl;
	cout << "按“1”键 “确定”" << endl;
	cout << "按其他键放弃清空" << endl;
	int a = 0;
	cin >> a;
	if (a == 1)
	{
		abs->A_size == 0;	
		cout << "通讯录已清空" << endl;
	}

	system("pause");
	system("cls");
}
int main()
{
	//创建一个通讯录结构体变量
struct Addressbooks abs;
	//初始化通讯录中当前人员数
abs.A_size = 0;

int select = 0;//创建用户选择输入变量
    while (1)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addlxr(&abs);//利用地址传递可以修饰实参
			break;
		case 2:
			showperson(&abs);//显示联系人			
			break;
		case 3:
			shanchulxr(&abs);//删除联系人
			break;
		case 4:
			findperson(&abs);//查找联系人
			break;
		case 5:
			modifyperson(&abs);//修改联系人
			break;
		case 6:
			clearall(&abs);//清空联系人
			break;
		case 0://推出通信录
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
