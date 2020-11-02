#include"student.h"
//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���
Student::Student(int id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComID && ifs >> c.m_MaxNum)
	{
		com.push_back(c);
	}
}
//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ��  " << this->m_Name << "  ��¼��" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.����ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.�鿴�ҵ�ԤԼ      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         3.�鿴����ԤԼ      |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         4.ȡ��ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.ע����¼          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "����������ѡ��";
 }
//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;//����
	int intervavl = 0;//ʱ���
	int room = 0;//�������
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "��ѡ������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (1)
	{
		cin >> intervavl;
		if (intervavl >= 1 && intervavl <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < com.size(); i++)
	{
		cout << "�����ı�ţ�" << com[i].m_ComID << "\t" << "����������Ϊ��" << com[i].m_MaxNum << endl;
	}
	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ�������У�" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);//��׷�ӵķ�ʽд�ļ�
	ofs << "date:" << date << " ";
	ofs << "interval:" << intervavl << " ";
	ofs << "stuID:" << this->m_ID << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "room:" << room << " ";
	ofs << "status:" << 1 << endl;//1��ʾ����е�״̬
	ofs.close();
	system("pause");
	system("cls");
}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string ת int
		//string ���� .c_str() תΪconst char *
		//����atoi(cont char*)תΪ int
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))//�ҵ������ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << "\t";
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")<<"\t";
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
	}
	system("pause");
	system("cls");
}
//�鿴�����˵�ԤԼ
void Student::allOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
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
//ȡ��ԤԼ
void  Student::cancelOrder()
{
	vector<int>v;//�������������е��±���
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼�ǿ���ȡ����,������Ҫȡ���ļ�¼��" << endl;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//�ж��Ƿ�Ϊ����ѧ��
		if (this->m_ID == atoi(of.m_orderData[i]["stuID"].c_str()))
		{
		
			//ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
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
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << "ԤԼ״̬��" << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
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
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}