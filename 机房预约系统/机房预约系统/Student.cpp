#include"student.h"
//默认构造
Student::Student()
{

}
//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComID && ifs >> c.m_MaxNum)
	{
		com.push_back(c);
	}
}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生  " << this->m_Name << "  登录！" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.申请预约          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.查看我的预约      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         3.查看所有预约      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         4.取消预约          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.注销登录          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "请输入您的选择：";
 }
//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;//日期
	int intervavl = 0;//时间段
	int room = 0;//机房编号
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "请选择申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (1)
	{
		cin >> intervavl;
		if (intervavl >= 1 && intervavl <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房：" << endl;
	for (int i = 0; i < com.size(); i++)
	{
		cout << "机房的编号：" << com[i].m_ComID << "\t" << "机房的容量为：" << com[i].m_MaxNum << endl;
	}
	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中！" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);//以追加的方式写文件
	ofs << "date:" << date << " ";
	ofs << "interval:" << intervavl << " ";
	ofs << "stuID:" << this->m_ID << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "room:" << room << " ";
	ofs << "status:" << 1 << endl;//1表示审核中的状态
	ofs.close();
	system("pause");
	system("cls");
}
//查看我的预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string 转 int
		//string 利用 .c_str() 转为const char *
		//利用atoi(cont char*)转为 int
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))//找到自身的预约
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"] << "\t";
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")<<"\t";
			cout << "机房号：" << of.m_orderData[i]["room"] << "\t";
			string status = "状态:";
			//1审核 2已预约 -1预约失败 0取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过";
			}
			if (of.m_orderData[i]["status"] == "0")
			{
				status += "预约取消";
			}
			cout << "预约状态：" << status << endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有人的预约
void Student::allOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"] << "\t";
		cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
		cout << "学号：" << of.m_orderData[i]["stuID"] << "\t";
		cout << "姓名：" << of.m_orderData[i]["stuName"] << "\t";
		cout << "机房号：" << of.m_orderData[i]["room"] << "\t";
		string status = "状态:";
		//1审核 2已预约 -1预约失败 0取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		if (of.m_orderData[i]["status"] == "0")
		{
			status += "预约取消";
		}
		cout << "预约状态：" << status << endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void  Student::cancelOrder()
{
	vector<int>v;//存放在最大容器中的下标编号
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的纪录是可以取消的,请输入要取消的记录：" << endl;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//判断是否为自身学号
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))
		{
		
			//筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << "\t";
				cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << "\t";
				cout << "机房号：" << of.m_orderData[i]["room"] << "\t";
				string status = "状态:";
				//1审核 2已预约 -1预约失败 0取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << "预约状态：" << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select ==0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "取消预约成功" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}