#include"Manager.h"
//析构函数
Manger::Manger(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//显示个人信息
void Manger::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工名称：" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:完成老板交给的任务，给员工颁发任务" << endl;
 }
//获得岗位名称
string Manger::getDeptname()
{
	return string("经理");
 }