#include"boss.h"
//��������
Boss::Boss(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ�����ƣ�" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:��Ǯ" << endl;
}
//��ø�λ����
string Boss::getDeptname()
{
	return string("�ϰ�");
}