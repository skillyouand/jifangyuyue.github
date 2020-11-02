#include"Manager.h"
//默认构造
Manager::Manager()
{
	
}	
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员的信息
	this->m_Name = name;
	this->m_Pwd = pwd;
	initVector();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComID && ifs >> com.m_MaxNum)
	{
		Com.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << Com.size() << endl;
}
//初始化容器
void Manager::initVector()
{
	s.clear();
	t.clear();
	ifstream ifs;
	//读取学生文件中的信息
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		return;
	}
	else
	{
		Student st;
		while (ifs >> st.m_ID && ifs >> st.m_Name && ifs >> st.m_Pwd)
		{
			s.push_back(st);
		}
		cout << "当前学生的数量为：" << s.size() << endl;
		ifs.close();
	}
	//读取老师文件中的信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		ifs.close();
		return;
	}
	else
	{
		Teacher te;
		while (ifs >> te.m_empID && ifs >> te.m_Name && ifs >> te.m_Pwd)
		{
			t.push_back(te);
		}
		cout << "当前老师的数量为：" << t.size() << endl;
		ifs.close();
	}

}
//查看是否有重复
bool Manager::CheckRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = s.begin(); it != s.end(); it++)
		{
			if (id == it->m_ID)
			{
				return  1;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = t.begin(); it != t.end(); it++)
		{
			if (id == it->m_empID)
			{
				return 1;
			}
		}
	}
	return 0;
}
//显示菜单
void Manager::operMenu()
{
	cout << "欢迎管理员  "<<this->m_Name<<"  登录！" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.添加账号          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.查看账号          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         3.查看机房          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         4.清空预约          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.注销登录          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "请输入您的选择：";
}
//添加账号
void Manager::addPerson()
{
	string ErrorTip;//重复错误提示
	string tip;//提示id号
	string filename;//操作的文件名
	ofstream ofs;
	while (1)
	{
		cout << "请输入添加账号的类型" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加老师" << endl;
		
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//添加的是学生
			filename = STUDENT_FILE;
			tip = "请输入学生的学号：";
			ErrorTip = "学生学号重复，请重新输入";
		}
		else if (select == 2)
		{	
			//添加的是老师
			filename = TEACHER_FILE;
			tip = "请输入教师的职工号：";
			ErrorTip = "老师职工号重复，请重新输入";
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
		//利用追加的方式 写文件
		ofs.open(filename, ios::out | ios::app);
		int id;
		string name;
		string pwd;
		cout << tip;
		cin >> id;
		bool ret = CheckRepeat(id, select);
		if (ret)//有重复
		{
			cout << ErrorTip << endl;
			system("pause");
			system("cls");
			break;
		}
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入密码：" << endl;
		cin >> pwd;
		//向文件中添加数据
		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "添加数据成功" << endl;
		this->initVector();
		system("pause");
		system("cls");
		ofs.close();
		break;
	}


	
	
}
//打印学生信息
void print(Student &s)
{
	cout << "学号：" << s.m_ID << "\t" << "姓名：" << s.m_Name << "\t" << "密码：" << s.m_Pwd << endl;
}
//打印老师信息
void prints(Teacher& t)
{
	cout << "职工号：" << t.m_empID << "\t" << "姓名：" << t.m_Name << "\t" << "密码：" << t.m_Pwd << endl;
}
//显示学生信息或者教师信息
void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout <<"1.查看所有学生信息" << endl;
	cout << "2.查看所有老师信息" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生的信息如下：" << endl;
		for_each(s.begin(), s.end(), print);
	}
	else if (select == 2)
	{
		cout << "所有老师的信息如下：" << endl;
		for_each(t.begin(), t.end(), prints);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = Com.begin(); it != Com.end(); it++)
	{
		cout << "机房的编号：" << it->m_ComID << "\t" << "机房的容量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::clearFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}