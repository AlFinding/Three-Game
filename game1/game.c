#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"

void initboard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			else
				printf("\n");
		}

		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
				else
					printf("\n");
			}
		}
	}
}

void player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请下棋》");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("坐标被占用,请重新输入");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				displayboard(board, row, col);
				break;
			}
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}
}

void computer(char board[ROW][COL],int row,int col)
{
	system("cls");
	printf("电脑下棋\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ' )
		{
			board[x][y] = '#';
			displayboard(board, row, col);
			break;
		}
		
	}

}

int check(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 1;
	for (i = 0; i <= row - 1; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			j = 0;
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			j = 0;
	}
	if (board[1][1] != ' ' && board[2][2] == board[1][1] && board[1][1] == board[0][0])
		j = 0;
	if (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		j = 0;
	return j;
}

