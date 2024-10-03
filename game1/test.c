#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"

void menu()
{

	printf("***************************\n");
	printf("**********1.play***********\n");
	printf("**********0.quit***********\n");
	printf("***************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board,ROW,COL);
	displayboard(board,ROW,COL);
	int x = 1;
	while (x)
	{
		player(board, ROW, COL);
		x = check(board, ROW, COL);
		if (x == 1)
		{
			computer(board, ROW, COL);
			x = check(board, ROW, COL);
			if (x == 0)
				printf("computer wins\n");
		
		}
		else
		{
			system("cls");
			displayboard(board, ROW, COL);
			printf("player wins\n");
		}

	}

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();
		printf("");
		scanf_s("%d", &input);
		system("cls");

		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("quit");
			break;
		default:
			printf("wrong");
			break;
		}
	} while (input);
}


