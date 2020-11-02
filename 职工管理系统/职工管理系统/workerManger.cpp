#include"workerManger.h"
//��ʼ������
WorkerManher::WorkerManher()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ�
	//�ļ�������ʱ��ʼ��
	if (!ifs.is_open())
	{	
		//���Դ���
		/*cout << "�ļ�������" << endl;*/
		//��ʼ������
		this->Emp_array = 0;
		this->m_emp = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����������Ϊ��ʱ
	char c;
	ifs >> c;
	if (ifs.eof())
	{
		//���Դ���
		/*cout << "�ļ�Ϊ��" << endl;*/
		//��ʼ������
		this->Emp_array = 0;
		this->m_emp = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڲ�������
	
	int num = this->get_num();
	//���Դ���
	//cout << "ְ������Ϊ��" <<num<< endl;
	this->Emp_array =num;
	//���ٿռ�
	this->m_emp = new Worker * [num];
	//���ļ������ݱ��浽������
	this->init_Emp();
	//���Դ���
	/*for (int i = 0; i < this->Emp_array; i++)
	{
		cout << "ְ�����" << this->m_emp[i]->m_ID << " "
			<< "����" << this->m_emp[i]->m_Name << " "
			<< "���ű��" << this->m_emp[i]->m_DeptID << endl;
	}*/
}
//չʾ�˵�
 void WorkerManher:: Show_Menu()
{
	 cout << "***********************************************" << endl;
	 cout << "*************��ӭʹ��ְ������ϵͳ**************"<<endl;
	 cout << "***************0.�˳��������******************" << endl;
	 cout << "***************1.����ְ����Ϣ******************" << endl;
	 cout << "***************2.��ʾְ����Ϣ******************" << endl;
	 cout << "***************3.ɾ����ְְ��******************" << endl;
	 cout << "***************4.�޸�ְ����Ϣ******************" << endl;
	 cout << "***************5.����ְ����Ϣ******************" << endl;
	 cout << "***************6.���ձ������******************" << endl;
	 cout << "***************7.��������ĵ�******************" << endl;
	 cout << "***********************************************" << endl;
}
 //���Ա��
 void WorkerManher::add_Emp()
 { 
	 cout << "������Ҫ��ӵĳ�Ա������" << endl;
	 int newpeople = 0;
	 cin >> newpeople;
	 if (newpeople > 0)
	 {
		//�����Ա
		 //��������¿ռ�Ĵ�С
		 int newsize = this->Emp_array + newpeople;
		 //�����¿ռ�
		 Worker** space = new Worker * [newsize];
		 //��ԭ���ռ��µ����ݷŵ��¿��ٵĿռ���ȥ
		 if (this->Emp_array != 0)
		 {
			 for (int i = 0; i < this->Emp_array; i++)
			 {
				 space[i] = this->m_emp[i];
			 }
		 }
		 //����µ�����
		 for (int i = 0; i < newpeople; i++)
		 {
			 int id;//ְ�����
			 string name;//ְ������
			 int dselect;//ְ������
			 cout << "�������  " << i + 1 << " ��ְ���ı�ţ�" << endl;
			 cin >> id;
			 cout << "�������  " << i + 1 << " ��ְ����������" << endl;
			 cin >> name;
			 Worker* worker = NULL;
			 cout << "�������  " << i + 1 << " ��ְ����ְҵ��" <<
				 "\n1.��ͨԱ��" << "\n2.����" << "\n3.�ϰ�" << endl;
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
				 cout << "������������������" << endl;
				 break;

			 }
			 //��������ְ��ְ�𱣴浽������
			 space[this->Emp_array + i] = worker;
		 }
		 //�����¿ռ�ָ��
		 this->m_emp = space;
		 //����ְ������
		 this->Emp_array = newsize;
		 //����ְ����Ϊ�ձ�־
		 this->m_FileIsEmpty = 0;
		 //��ʾ��ӳɹ�
		 cout << "�ɹ����" << newpeople << "��Ա��" << endl;
		 //���浽�ļ���
		 this->save();
		 system("pause");
		 system("cls");
	}
	 else
	 {
		 cout << "������������" << endl;
	 }
 }
 //�˳�ϵͳ
 void WorkerManher::exitsystem()
 {
	 cout << "��ӭ�´�ʹ��" << endl;
	 system("pause");
	 exit(0);
 }
 //���浽�ļ�
 void WorkerManher::save()
 {
	 ofstream ofs;
	 ofs.open(FILENAME, ios::out);//д�ļ�
	//��ÿ���˵�����д���ļ���
	 for (int i = 0; i < this->Emp_array; i++)
	 {
		 ofs << this->m_emp[i]->m_ID << "  "
			 << this->m_emp[i]->m_Name << "  "
			 << this->m_emp[i]->m_DeptID << endl;
	 }
	 ofs.close();
 }
 //ͳ���ļ��г�Ա������
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
		 //ͳ����������
		 num++;
	 }
	 return(num);
 }
 //��ʼ��Ա��
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
	 //�ر��ļ�
	 ifs.close();
 }
 //��ʾԱ��
 void WorkerManher::show_emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
	 }
	 else
	 {
		 for (int i = 0; i < this->Emp_array; i++)
		 {
			 //���ö�̬���ýӿ�
			 this->m_emp[i]->showInfo();
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //�ж�Ա���Ƿ����    ���ձ��
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
 //ɾ��Ա��
 void WorkerManher::Del_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	 else
	 {
		 //���ձ��ɾ��
		 cout << "��������Ҫɾ����ְ����ţ�" << endl;
		 int id = 0;
		 cin >> id;
		 int index = this->IsExist(id);
		 if (index != -1)
		 {
			 for (int i = index; i < this->Emp_array - 1; i++)
			 {
				 //����Ǩ��
				 this->m_emp[i] = this->m_emp[i + 1];
			 }
			 //������������Ա����
			 this->Emp_array--;
			 //���µ��ļ���
			 this->save();
			 cout << "ɾ���ɹ�" << endl;
		 }
		 else
		 {
			 cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		 }
		 system("pause");
		 system("cls");
	 }
 }
 //�޸�Ա��
 void WorkerManher::Mod_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
	 }
	 else
	 {
		 cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		 int id;
		 cin >> id;
		 int ret = this->IsExist(id);
		 if (ret != -1)
		 {
			 //���ҵ���ŵ�ְ��
			 delete this->m_emp[ret];
			 int newid = 0;
			 string name;
			 int dselect = 0;
			 cout << "�鵽��" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			 cin >> newid;
			 cout << "�������µ�������" << endl;
			 cin>>name;
			 cout << "�������λ��" << endl;
			 cout << "1.��ְͨ��" << endl;
			 cout << "2.����" << endl;
			 cout << "3.�ϰ�" << endl;
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
			 //�������ݵ�������
			 this->m_emp[ret] = worke;
			 cout << "�޸ĳɹ�" << endl;
			 //���浽�ļ���
			 this->save();
		 }
		 else
		 {
			 cout << "���޴���" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //����ְ��
 void WorkerManher::Find_EMp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
	 }
	 else
	 {
		 cout << "��������ҵķ�ʽ" << endl;
		 cout << "1.��ְ����Ų��ң�" << endl;
		 cout << "2.��ְ���������ң�" << endl;
		 int select = 0;
		 cin>>select;
		 if (select == 1)
		 {
			 //���ձ�Ų���
			 int id;
			 cout << "��������Ҫ���ҵ�Ա����ְ�����:" << endl;
			 cin >> id;
			 int ret = IsExist(id);
			 if (ret != -1)
			 {
				 cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				 this->m_emp[ret]->showInfo();
			 }
			 else
			 {
				 cout << "���޴���" << endl;
			 }

		 }
		 else if (select == 2)
		 {
			 //��������
			 string name;
			 cout << "����������˵�������" << endl;
			 cin >> name;
			 bool flag = false;//Ĭ��δ�ҵ�ְ��
			 for (int i = 0; i < this->Emp_array; i++)
			 {
				 if (this->m_emp[i]->m_Name == name)
				 {
					 cout << "���ҳɹ���ְ�����Ϊ�� " <<
						 this->m_emp[i]->m_ID << "��ְ������Ϣ���£�" << endl;
					 flag = true;
					 //��ʾ��Ϣ�ӿ�
					 this->m_emp[i]->showInfo();
				 }	
			 }
			 if (flag == false)
			 {
				 cout << "���޴���" << endl;
			 }
		 }
		 else
		 {
			 cout << "����������" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }
 //����
 void WorkerManher::Sort_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ��������ڻ��¼Ϊ��" << endl;
		 system("pause");
		 system("cls");
	 }
	 else
	 {
		 cout << "��ѡ������ķ�ʽ��" << endl;
		 cout << "1.��ְ���Ž�������" << endl;
		 cout << "2.��ְ���Ž��н���" << endl;
		 int select;
		 cin >> select;
		 
		 for (int i = 0; i < this->Emp_array; i++)
		 {
			 int max = i;
			 for (int j = i + 1; j < this->Emp_array; j++)
			 {
				 if (select == 1)//����
				 {
					 if (m_emp[max]->m_ID > m_emp[j]->m_ID)
					 {
						 max = j;
					 }
				 }
				 else//����
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
		 cout << "����ɹ��������Ľ��Ϊ��" << endl;
		 this->save();
		 this->show_emp();
	 }
 }
 //����ļ�
 void WorkerManher::Clean_Emp()
 {
	 cout << "�Ƿ�ȷ�����" << endl;
	 cout << "����1��ȷ��" << endl;
	 cout << "����2������" << endl;
	 int select = 0;
	 cin >> select;
	 if (select == 1)
	 {
		 ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
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
			 //ɾ����������ָ��
			 this->Emp_array = 0;
			 delete[]this->m_emp;
			 this->m_emp = NULL;
			 this->m_FileIsEmpty = true;
		 }
		 cout << "��ճɹ�" << endl;
	 }
	 system("pause");
	 system("cls");
 }
 //����
 WorkerManher::~WorkerManher()
{
	 if (this->Emp_array != NULL)
	 {
		 delete[]this->m_emp;
		 this->m_emp = NULL;
	 }
}
