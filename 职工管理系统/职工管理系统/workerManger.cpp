#include"workerManger.h"
//初始化属性
WorkerManher::WorkerManher()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//读文件
	//文件不存在时初始化
	if (!ifs.is_open())
	{	
		//测试代码
		/*cout << "文件不存在" << endl;*/
		//初始化属性
		this->Emp_array = 0;
		this->m_emp = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在且数据为空时
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		//测试代码
		/*cout << "文件为空" << endl;*/
		//初始化属性
		this->Emp_array = 0;
		this->m_emp = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在并有数据
	
	int num = this->get_num();
	//测试代码
	//cout << "职工人数为：" <<num<< endl;
	this->Emp_array =num;
	//开辟空间
	this->m_emp = new Worker * [num];
	//将文件的数据保存到数组中
	this->init_Emp();
	//测试代码
	/*for (int i = 0; i < this->Emp_array; i++)
	{
		cout << "职工编号" << this->m_emp[i]->m_ID << " "
			<< "姓名" << this->m_emp[i]->m_Name << " "
			<< "部门编号" << this->m_emp[i]->m_DeptID << endl;
	}*/
}
//展示菜单
 void WorkerManher:: Show_Menu()
{
	 cout << "***********************************************" << endl;
	 cout << "*************欢迎使用职工管理系统**************"<<endl;
	 cout << "***************0.退出管理程序******************" << endl;
	 cout << "***************1.增加职工信息******************" << endl;
	 cout << "***************2.显示职工信息******************" << endl;
	 cout << "***************3.删除离职职工******************" << endl;
	 cout << "***************4.修改职工信息******************" << endl;
	 cout << "***************5.查找职工信息******************" << endl;
	 cout << "***************6.按照编号排序******************" << endl;
	 cout << "***************7.清空所有文档******************" << endl;
	 cout << "***********************************************" << endl;
}
 //添加员工
 void WorkerManher::add_Emp()
 { 
	 cout << "请输入要添加的成员人数：" << endl;
	 int newpeople = 0;
	 cin >> newpeople;
	 if (newpeople > 0)
	 {
		//添加人员
		 //计算添加新空间的大小
		 int newsize = this->Emp_array + newpeople;
		 //开辟新空间
		 Worker** space = new Worker * [newsize];
		 //将原来空间下的数据放到新开辟的空间下去
		 if (this->Emp_array != 0)
		 {
			 for (int i = 0; i < this->Emp_array; i++)
			 {
				 space[i] = this->m_emp[i];
			 }
		 }
		 //添加新的数据
		 for (int i = 0; i < newpeople; i++)
		 {
			 int id;//职工编号
			 string name;//职工名字
			 int dselect;//职工部门
			 cout << "请输入第  " << i + 1 << " 个职工的编号：" << endl;
			 cin >> id;
			 cout << "请输入第  " << i + 1 << " 个职工的姓名：" << endl;
			 cin >> name;
			 Worker* worker = NULL;
			 cout << "请输入第  " << i + 1 << " 个职工的职业：" <<
				 "\n1.普通员工" << "\n2.经理" << "\n3.老板" << endl;
			 cin >> dselect;
			 switch (dselect)
			 {
			 case 1:
				 worker = new Employee(id, name, 3);
				 break;
			 case 2:
				 worker = new Manger(id, name, 2);
				 break;
			 case 3:
				 worker = new Boss(id, name, 1);
				 break;
			 default:
				 cout << "输入有误，请重新输入" << endl;
				 break;

			 }
			 //将创建的职工职责保存到数组中
			 space[this->Emp_array + i] = worker;
		 }
		 //更改新空间指向
		 this->m_emp = space;
		 //更新职工数量
		 this->Emp_array = newsize;
		 //更新职工不为空标志
		 this->m_FileIsEmpty = 0;
		 //提示添加成功
		 cout << "成功添加" << newpeople << "名员工" << endl;
		 //保存到文件中
		 this->save();
		 system("pause");
		 system("cls");
	}
	 else
	 {
		 cout << "输入数据有误" << endl;
	 }
 }
 //退出系统
 void WorkerManher::exitsystem()
 {
	 cout << "欢迎下次使用" << endl;
	 system("pause");
	 exit(0);
 }
 //保存到文件
 void WorkerManher::save()
 {
	 ofstream ofs;
	 ofs.open(FILENAME, ios::out);//写文件
	//将每个人的数据写入文件中
	 for (int i = 0; i < this->Emp_array; i++)
	 {
		 ofs << this->m_emp[i]->m_ID << "  "
			 << this->m_emp[i]->m_Name << "  "
			 << this->m_emp[i]->m_DeptID << endl;
	 }
	 ofs.close();
 }
 //统计文件中成员的人数
 int WorkerManher::get_num()
 {
	 ifstream ifs;
	 int id;
	 string name;
	 int did;
	 int num = 0;
	 ifs.open(FILENAME, ios::in);
	 while (ifs >> id && ifs >> name && ifs >> did)
	 {	
		 //统计人数变量
		 num++;
	 }
	 return(num);
 }
 //初始化员工
 void  WorkerManher::init_Emp()
 {
	 ifstream ifs;
	 ifs.open(FILENAME, ios::in);
	 int id;
	 string name;
	 int did;
	 int i = 0;
	 while (ifs >> id && ifs >> name && ifs >> did)
	 {
		 Worker* worker = NULL;
		 if (did == 1)
		 {
			 worker = new Employee(id, name, did);
		 }
		 else if (did == 2)
		 {
			 worker = new Manger(id, name, did);
		 }
		 else
		 {
			 worker = new Boss(id, name, did);
		 }
		 this->m_emp[i] = worker;
		 i++;
	 }
	 //关闭文件
	 ifs.close();
 }
 //显示员工
 void WorkerManher::show_emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	 }
	 else
	 {
		 for (int i = 0; i < this->Emp_array; i++)
		 {
			 //利用多态调用接口
			 this->m_emp[i]->showInfo();
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //判断员工是否存在    按照编号
int WorkerManher::IsExist(int id)
 {
	int index=-1;
	 for (int i = 0; i < this->Emp_array; i++)
	 {
		 if (this->m_emp[i]->m_ID == id)
		 {
			 index = i;
			 break;
		 }
	 }
	 return index;
 }
 //删除员工
 void WorkerManher::Del_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	}
	 else
	 {
		 //按照编号删除
		 cout << "请输入想要删除的职工编号：" << endl;
		 int id = 0;
		 cin >> id;
		 int index = this->IsExist(id);
		 if (index != -1)
		 {
			 for (int i = index; i < this->Emp_array - 1; i++)
			 {
				 //数据迁移
				 this->m_emp[i] = this->m_emp[i + 1];
			 }
			 //更新数组中人员个数
			 this->Emp_array--;
			 //更新到文件中
			 this->save();
			 cout << "删除成功" << endl;
		 }
		 else
		 {
			 cout << "删除失败，未找到该职工" << endl;
		 }
		 system("pause");
		 system("cls");
	 }
 }
 //修改员工
 void WorkerManher::Mod_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	 }
	 else
	 {
		 cout << "请输入要修改的职工编号：" << endl;
		 int id;
		 cin >> id;
		 int ret = this->IsExist(id);
		 if (ret != -1)
		 {
			 //查找到编号的职工
			 delete this->m_emp[ret];
			 int newid = 0;
			 string name;
			 int dselect = 0;
			 cout << "查到：" << id << "号职工，请输入新的职工号：" << endl;
			 cin >> newid;
			 cout << "请输入新的姓名：" << endl;
			 cin>>name;
			 cout << "请输入岗位：" << endl;
			 cout << "1.普通职工" << endl;
			 cout << "2.经理" << endl;
			 cout << "3.老板" << endl;
			 cin >> dselect;
			 Worker* worke = NULL;
			 switch (dselect)
			 {
			 case 1:
				 worke = new Employee(newid, name, dselect);
				 break;
			 case 2:
				 worke = new Manger(newid, name, dselect);
				 break;
			 case 3:
				 worke = new Boss(newid, name, dselect);
				 break;
			 default:
				 break;
			 }
			 //更新数据到数组中
			 this->m_emp[ret] = worke;
			 cout << "修改成功" << endl;
			 //保存到文件中
			 this->save();
		 }
		 else
		 {
			 cout << "查无此人" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //查找职工
 void WorkerManher::Find_EMp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	 }
	 else
	 {
		 cout << "请输入查找的方式" << endl;
		 cout << "1.按职工编号查找：" << endl;
		 cout << "2.按职工姓名查找：" << endl;
		 int select = 0;
		 cin>>select;
		 if (select == 1)
		 {
			 //按照编号查找
			 int id;
			 cout << "请输入你要查找的员工的职工编号:" << endl;
			 cin >> id;
			 int ret = IsExist(id);
			 if (ret != -1)
			 {
				 cout << "查找成功，该职工信息如下：" << endl;
				 this->m_emp[ret]->showInfo();
			 }
			 else
			 {
				 cout << "查无此人" << endl;
			 }

		 }
		 else if (select == 2)
		 {
			 //按照姓名
			 string name;
			 cout << "请输入查找人的姓名：" << endl;
			 cin >> name;
			 bool flag = false;//默认未找到职工
			 for (int i = 0; i < this->Emp_array; i++)
			 {
				 if (this->m_emp[i]->m_Name == name)
				 {
					 cout << "查找成功！职工标号为： " <<
						 this->m_emp[i]->m_ID << "号职工的信息如下：" << endl;
					 flag = true;
					 //显示信息接口
					 this->m_emp[i]->showInfo();
				 }	
			 }
			 if (flag == false)
			 {
				 cout << "查无此人" << endl;
			 }
		 }
		 else
		 {
			 cout << "输入项有误" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //排序
 void WorkerManher::Sort_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件包不存在或记录为空" << endl;
		 system("pause");
		 system("cls");
	 }
	 else
	 {
		 cout << "请选择排序的方式：" << endl;
		 cout << "1.按职工号进行升序" << endl;
		 cout << "2.按职工号进行降序" << endl;
		 int select;
		 cin >> select;
		 
		 for (int i = 0; i < this->Emp_array; i++)
		 {
			 int max = i;
			 for (int j = i + 1; j < this->Emp_array; j++)
			 {
				 if (select == 1)//升序
				 {
					 if (m_emp[max]->m_ID > m_emp[j]->m_ID)
					 {
						 max = j;
					 }
				 }
				 else//降序
				 {
					 if (m_emp[max]->m_ID < m_emp[j]->m_ID)
					 {
						 max = j;
					 }
				 }
			 }
			 if (i != max)
			 {
				 Worker* temp = m_emp[i];
				 m_emp[i] = m_emp[max];
				 m_emp[max] = temp;
			 }
		 }
		 cout << "排序成功，排序后的结果为：" << endl;
		 this->save();
		 this->show_emp();
	 }
 }
 //清空文件
 void WorkerManher::Clean_Emp()
 {
	 cout << "是否确定清空" << endl;
	 cout << "按‘1’确认" << endl;
	 cout << "按‘2’返回" << endl;
	 int select = 0;
	 cin >> select;
	 if (select == 1)
	 {
		 ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		 ofs.close();
		 if (this->m_emp != NULL)
		 {
			 for (int i = 0; i < this->Emp_array; i++)
			 {
				 if (this->m_emp[i] != NULL)
				 {
					 delete this->m_emp[i];
				 }
					 
			 }
			 //删除堆区数组指针
			 this->Emp_array = 0;
			 delete[]this->m_emp;
			 this->m_emp = NULL;
			 this->m_FileIsEmpty = true;
		 }
		 cout << "清空成功" << endl;
	 }
	 system("pause");
	 system("cls");
 }
 //析构
 WorkerManher::~WorkerManher()
{
	 if (this->Emp_array != NULL)
	 {
		 delete[]this->m_emp;
		 this->m_emp = NULL;
	 }
}
