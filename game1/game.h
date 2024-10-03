#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);

//打印棋盘
void displayboard(char board[ROW][COL], int row, int col);

//选手下棋
void player(char board[ROW][COL], int row, int col);

//电脑下棋
void computer(char board[ROW][COL], int row, int col);

int check(char board[ROW][COL], int row, int col);