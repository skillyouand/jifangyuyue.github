//1.测试三子棋模块
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include"game.h"
//游戏菜单
void menu()
{
	printf("***********************************\n");
	printf("**********1.Play  0.Exit***********\n");
	printf("***********************************\n");
}
//游戏整个算法的实现
void game()
{
	char ret;
	//数组-存放玩家和电脑走出的期盼信息
	char board[ROW][COL] = {0};//全部是空格
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		system("pause");
		ret = IsWin(board, ROW, COL);
		//判断玩家是否赢
		if (ret !='c')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		system("pause");
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret !='c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获得胜利\n");
		system("pause");
		system("cls");
	}
	else if (ret == '#')
	{
		printf("电脑获得胜利\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("平局\n");
		system("pause");
		system("cls");
	}
}
void test()
{
	char input;
	do {
		menu();
		printf("请选择：>:\n");
		scanf_s("%c\n", &input);
		switch (input)
		{
		case '1':
			printf("三子棋\n");
			game();
			break;
		case '0':
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
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