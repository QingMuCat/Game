#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//猜数字小游戏,根据猜对次数给予奖励语句

void print_score(int count)
{
	if (1 == count)
	{
		printf("简直太棒啦！为你颁发猜数字的小达人证书！！！ \n");//1次
	}
	else if (count >= 2 && count <= 4)
	{
		printf("相当不错，又被你猜到了哦 \n");//2-4次
	}
	else if (count >= 5 && count <= 8)
	{
		printf("水平一般般啦，不行呀\n");//5-8次
	}
	else
	{
		printf("没有发挥你的全部实力哦~ 运气有点差，再来一局吧\n");//>8次
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
	int count = 0;// 记录猜对次数，给予判定
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
			print_score(count);//输出"void print_score(int count)"内容
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
			Sleep(1000);//防止进程阻塞，让程序休眠
			break;
		default:
			printf("选择错误，请重新输入！\n");
		}
	} while (input);
	return 0;
}