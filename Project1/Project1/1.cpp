#include<iostream>
using namespace std;
#include<string>
#define max 1000
//�����ϵ�˵Ľṹ��
struct lianxiren
{
	//��ϵ������Ϊ1000����ϵ�˵���Ϣ���������Ա����䣬��ϵ�绰����ͥסַ��
	//����
	string l_name;
	//�Ա� 1.�� 2.Ů
	int l_sex;
	//����
	int l_age;
	//�绰
	string l_phone;
	//סַ
	string l_addr;
};
//���ͨ��¼�Ľṹ
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct lianxiren A_people[max];
	//ͨѶ¼�е�ǰ��¼��ϵ����
	int A_size;
};
void showMenu()//��������
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨ��¼  *****" << endl;
	cout << "**************************" << endl;
}
void addlxr(Addressbooks *abs)//�����ϵ��
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->A_size == max)
	{
		cout << "ͨѶ¼���ˣ��޷����" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		//����
		string name;
		cout << "������ϵ������" << endl;
		cin >> name;
		abs->A_people[abs->A_size].l_name= name;
		//�Ա�
		int sex;
		cout << "������ϵ�˵��Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		while (1) //�������1��2������ѭ��
			//��������������˳�ѭ��
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->A_people[abs->A_size].l_sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//����
		int age;
		cout << "��������ϵ������" << endl;
		cin >> age;
		abs->A_people[abs->A_size].l_age = age;
		//�绰
		string phone;
		cout << "��������ϵ�˵绰" << endl;
		cin >> phone;
		abs->A_people[abs->A_size].l_phone = phone;
		//סַ
		string address;
		cout << "��������ϵ�˵�סַ" << endl;
		cin >> address;
		abs->A_people[abs->A_size].l_addr = address;
		//����ͨѶ¼����
		abs->A_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showperson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ��
	if (abs->A_size == 0)
	{
		cout << "ͨѶ¼�����ڻ�û����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->A_size; i++)
		{
			cout << "����:" << abs->A_people[i].l_name << "\t";
			cout << "����:" << abs->A_people[i].l_age << "\t";
			cout << "�Ա�:" <<(abs->A_people[i].l_sex == 1?"��":"Ů")<< "\t";
			cout << "�绰:"<< abs->A_people[i].l_phone << "\t";
			cout << "��ַ:" << abs->A_people[i].l_addr << endl;
		}
		
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ�����ڵľ���λ�ã��������򷵻�-1
int isexist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->A_size; i++)
	{
		//�ҵ��û����������
		if (abs->A_people[i].l_name == name)
		{
			return i;
		}
		
	}
	return -1;
}
//ɾ��ָ����ϵ��
void shanchulxr(Addressbooks *abs)
{
	cout << "������ɾ������ϵ������:" << endl;
	string name;
	cin >> name;
	int a = isexist(abs, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = a; i < abs->A_size; i++)
		{
			//����ǰ��
			abs->A_people[i] = abs->A_people[i + 1];
		}
		abs->A_size--;//����ͨѶ¼�г�Ա����
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//����ָ����ϵ����Ϣ
void findperson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int a=isexist(abs, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << abs->A_people[a].l_name << "\t";
		cout << "�Ա�" << (abs->A_people[a].l_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->A_people[a].l_age << "\t";
		cout << "�绰��" << abs->A_people[a].l_phone << "\t";
		cout << "��ַ��" << abs->A_people[a].l_addr << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ָ������ϵ����Ϣ
void modifyperson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ����Ϣ" << endl;
	string name;
	cin >> name;
	int a=isexist(abs, name);
	if (a == -1)
	{
		cout << "û���ҵ�Ҫ�޸ĵ���ϵ��" << endl;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->A_people[a].l_name = name;
		int sex;
		cout << "�������Ա�" <<endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while(1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->A_people[a].l_sex = sex;
				break;
			}
			else
			{
				cout << "�����������������" << endl;

			}
			
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->A_people[a].l_age = age;
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->A_people[a].l_phone = phone;
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->A_people[a].l_addr = address;
		cout << "�޸ĳɹ�" << endl;
		cout << "������" << abs->A_people[a].l_name << "\t";
		cout << "�Ա�" << (abs->A_people[a].l_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->A_people[a].l_age << "\t";
		cout << "�绰��" << abs->A_people[a].l_phone << "\t";
		cout << "��ַ��" << abs->A_people[a].l_addr << endl;
		system("pause");
		system("cls");
	}
}
//�����ϵ��
void clearall(Addressbooks *abs)
{
	//����ǰ��¼����ϵ��������Ϊ0����һ���߼��ϵ����
	cout << "ȷ���Ƿ�Ҫȫ�����" << endl;
	cout << "����1���� ��ȷ����" << endl;
	cout << "���������������" << endl;
	int a = 0;
	cin >> a;
	if (a == 1)
	{
		abs->A_size == 0;	
		cout << "ͨѶ¼�����" << endl;
	}

	system("pause");
	system("cls");
}
int main()
{
	//����һ��ͨѶ¼�ṹ�����
struct Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա��
abs.A_size = 0;

int select = 0;//�����û�ѡ���������
    while (1)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addlxr(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2:
			showperson(&abs);//��ʾ��ϵ��			
			break;
		case 3:
			shanchulxr(&abs);//ɾ����ϵ��
			break;
		case 4:
			findperson(&abs);//������ϵ��
			break;
		case 5:
			modifyperson(&abs);//�޸���ϵ��
			break;
		case 6:
			clearall(&abs);//�����ϵ��
			break;
		case 0://�Ƴ�ͨ��¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
