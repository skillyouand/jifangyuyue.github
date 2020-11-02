
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW	3//期盼的行数
#define COL 3//棋盘的列数
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);//打印棋盘
void PlayerMove(char board[ROW][COL],int row,int col);//玩家下棋
void ComputerMove(char board[ROW][COL],int row,int col);//电脑下棋
char IsWin(char board[ROW][COL], int row, int col);//玩家赢 电脑赢 平手 继续