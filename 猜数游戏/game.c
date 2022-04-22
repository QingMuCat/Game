﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//猜数字小游戏,根据猜对次数给予奖励语句

void print_score(int count)
{
	if (1 == count)
	{
		printf("猜数字的小达人！！！ \n");
	}
	else if (count >= 2 && count <= 4)
	{
		printf("相当不错，就被你猜到了 \n");
	}
	else if (count >= 5 && count <= 8)
	{
		printf("水平一般般，不行呀\n");
	}
	else
	{
		printf("没有发挥你的全部实力，运气有点差，再来一局吧\n");
	}
}

//  游戏菜单部分

void menu()
{
	printf("********************************\n");
	printf("*******欢迎来到猜数字游戏*******\n");
	printf("************请选择>:************\n");
	printf("******1.Start        0.Exit******\n");
	printf("********************************\n");
}

// 游戏部分

void game()
{
	int ret = rand() % 100 + 1;   //用来产生1-100之间的随机数
	int guess = 0;
	int max = 100;
	int min = 0;
	while (1)
	{

		printf("请猜数字:>\n");
		scanf_s("%d", &guess);//vs2022使用scanf无法进行编译，需使用scanf_s可过编译
		if (guess > ret)
		{
			printf("猜大了\n");
			max = guess;
			printf("猜测范围要在%d - %d\n", min, max);
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
			min = guess;
			printf("猜测范围要在%d - %d 之间\n", min, max);
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
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
		printf("请选择(1/0):>");
		scanf_s("%d", &input);//vs2022使用scanf无法进行编译，需使用scanf_s可过编译
		switch (input)
		{
		case 0:
			printf("退出游戏");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误，请重新输入！\n");
		}
	} while (input);
	return 0;
}