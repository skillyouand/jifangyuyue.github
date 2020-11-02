#include"orderFile.h"
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;//日期
	string interval;//时间段
	string stuID;//学生编号
	string stuName;//学生姓名
	string room;//机房编号
	string status;//预约状态
	this->m_size = 0;//记录条数
	while (ifs >> date && ifs >> interval && ifs >> stuID &&
		ifs >> stuName && ifs >> room && ifs >> status)
	{
		string key;
		string value;
		//截取日期
		int pos = date.find(":");
		map<string, string>m;
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取时间段
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取学号
		pos = stuID.find(":");
		if (pos != -1)
		{
			key = stuID.substr(0, pos);
			value = stuID.substr(pos + 1, stuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取姓名
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取机房号
		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取预约状态
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//将小的map容器放入到大的map容器当中
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
	//测试最大的map容器
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key=" << it->first << "value=" << endl;
		for (map<string, string>::iterator id = it->second.begin(); id != it->second.end(); id++)
		{
			cout << "key=" << id->first << "\tvalue=" << id->second << endl;
		}
	}*/
}
//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuID:" << this->m_orderData[i]["stuID"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "room:" << this->m_orderData[i]["room"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] <<endl;
	}
	ofs.close();
}

