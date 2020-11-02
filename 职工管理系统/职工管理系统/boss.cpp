#include"boss.h"
//析构函数
Boss::Boss(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工名称：" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:收钱" << endl;
}
//获得岗位名称
string Boss::getDeptname()
{
	return string("老板");
}