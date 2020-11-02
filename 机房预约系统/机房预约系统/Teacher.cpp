#include"teacher.h"
#include<fstream>
#include"ȫ���ļ����.h"
#include"orderFile.h"
#include<vector>
//Ĭ�Ϲ���
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int mepID, string name, string pwd)
{
	this->m_empID = mepID;
	this->m_Name = name;
	this->m_Pwd = pwd;

}
//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ  " << this->m_Name << "  ��¼��" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.�鿴����ԤԼ      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.���ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.ע����¼          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "����������ѡ��";
}
//�鿴����ԤԼ
void Teacher::showAllorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\t";
		cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\t";
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuID"] << "\t";
		cout << "������" << of.m_orderData[i]["stuName"] << "\t";
		cout << "�����ţ�" << of.m_orderData[i]["room"] << "\t";
		string status = "״̬:";
		//1��� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		if (of.m_orderData[i]["status"] == "0")
		{
			status += "ԤԼȡ��";
		}
		cout << "ԤԼ״̬��" << status << endl;
	}
	system("pause");
	system("cls");

}
//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if(of.m_size==0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\t";
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << "\t";
			cout << "�����ţ�" << of.m_orderData[i]["room"] << "\t";
			string status = "״̬:";
			//1��� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << "ԤԼ״̬��" << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0��ʾ����" << endl;
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
				cout << "��������˽����" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
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
		cout << "�����������������" << endl;
	}
	system("pause");
	system("cls");
}