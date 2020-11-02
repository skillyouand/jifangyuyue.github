#include"employee.h"
//析构函数
Employee::Employee(int id, string name, int deprtid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deprtid;
}
//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工名称：" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}
	 
//获得岗位名称
 string Employee::getDeptname()
{
	 return string("员工");
}

