#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
				
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走：>\n");
		printf("请输入要下的坐标：\n");
		scanf_s("%d%d", &x, &y);
		//判断X,Y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				DisplayBoard(board, ROW, COL);//打印棋盘
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			DisplayBoard(board, ROW, COL);//打印棋盘
			break;
		}
	}

}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两条对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	else if (board[0][2]== board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (1 == IsFull(board,ROW,COL))
	{
		return 'q';
	}
	return 'c';
}
int IsFull(char board[ROW][COL], int row, int col)//返回1表示棋盘满了，返回2表示棋盘没满
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}