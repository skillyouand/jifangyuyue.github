#include"employee.h"
//��������
Employee::Employee(int id, string name, int deprtid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deprtid;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ�����ƣ�" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:��ɾ�����������" << endl;
}
	 
//��ø�λ����
 string Employee::getDeptname()
{
	 return string("Ա��");
}

