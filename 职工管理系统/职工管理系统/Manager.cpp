#include"Manager.h"
//��������
Manger::Manger(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//��ʾ������Ϣ
void Manger::showInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ�����ƣ�" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:����ϰ彻�������񣬸�Ա���䷢����" << endl;
 }
//��ø�λ����
string Manger::getDeptname()
{
	return string("����");
 }