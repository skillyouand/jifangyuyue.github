//1.����������ģ��
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include"game.h"
//��Ϸ�˵�
void menu()
{
	printf("***********************************\n");
	printf("**********1.Play  0.Exit***********\n");
	printf("***********************************\n");
}
//��Ϸ�����㷨��ʵ��
void game()
{
	char ret;
	//����-�����Һ͵����߳���������Ϣ
	char board[ROW][COL] = {0};//ȫ���ǿո�
	InitBoard(board,ROW,COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		system("pause");
		ret = IsWin(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		if (ret !='c')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		system("pause");
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret !='c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ��ʤ��\n");
		system("pause");
		system("cls");
	}
	else if (ret == '#')
	{
		printf("���Ի��ʤ��\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("ƽ��\n");
		system("pause");
		system("cls");
	}
}
void test()
{
	char input;
	do {
		menu();
		printf("��ѡ��>:\n");
		scanf_s("%c\n", &input);
		switch (input)
		{
		case '1':
			printf("������\n");
			game();
			break;
		case '0':
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}