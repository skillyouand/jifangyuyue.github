#include"orderFile.h"
//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;//����
	string interval;//ʱ���
	string stuID;//ѧ�����
	string stuName;//ѧ������
	string room;//�������
	string status;//ԤԼ״̬
	this->m_size = 0;//��¼����
	while (ifs >> date && ifs >> interval && ifs >> stuID &&
		ifs >> stuName && ifs >> room && ifs >> status)
	{
		string key;
		string value;
		//��ȡ����
		int pos = date.find(":");
		map<string, string>m;
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡʱ���
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡѧ��
		pos = stuID.find(":");
		if (pos != -1)
		{
			key = stuID.substr(0, pos);
			value = stuID.substr(pos + 1, stuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡ����
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡ������
		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡԤԼ״̬
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��С��map�������뵽���map��������
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
	//��������map����
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key=" << it->first << "value=" << endl;
		for (map<string, string>::iterator id = it->second.begin(); id != it->second.end(); id++)
		{
			cout << "key=" << id->first << "\tvalue=" << id->second << endl;
		}
	}*/
}
//����ԤԼ��¼
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

