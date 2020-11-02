#include"teacher.h"
#include<fstream>
#include"全局文件添加.h"
#include"orderFile.h"
#include<vector>
//默认构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int mepID, string name, string pwd)
{
	this->m_empID = mepID;
	this->m_Name = name;
	this->m_Pwd = pwd;

}
//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师  " << this->m_Name << "  登录！" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.查看所有预约      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.审核预约          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.注销登录          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "请输入您的选择：";
}
//查看所有预约
void Teacher::showAllorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
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
//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
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
			cout << "预约状态：" << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0表示返回" << endl;
	int select = 0;
	int  ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				break;
			}
		}
		cout << "输入错误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}