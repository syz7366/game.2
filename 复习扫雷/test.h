#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<math.h>

#define wide 3
#define long 3
#define kills 3
void menu();
void game(char mine[wide+2][long+2], char show[wide][long]);
int my_decide(char show[wide][long]);
void my_print(char show[wide][long]);
void my_kill(char mine[wide+2][long+2]);
//void my_decide(int decide);
int my_player(char mine[wide+2][long+2], char show[wide][long]);
void my_check(char mine[wide+2][long+2],int x,int y);


void menu()
{	
	printf("**************************************\n");
	printf("**********   1.开始游戏   ************\n");
	printf("**********   0.结束游戏   ************\n");
	printf("**************************************\n");
}

void game(char mine[wide+2][long+2], char show[wide][long])
{	
	int decide = 1;
	while (decide)
	{
		decide=my_player(mine,show);
		//my_print(show);
		//my_check(mine);             放在这位置不好
		//my_decide();
		//my_decide();// 判断
	}

}


void my_print(char show[wide][long])
{
		for (int n = 0; n < wide + 1; n++)
		{
			printf("%d ",n);
		}
		printf("\n");
	for (int i = 0; i < long; i++)
	{
		printf("%d",i+1);
		for (int j = 0; j < wide; j++)
		{
			printf(" %c",show[i][j]);
		}
		printf("\n");
	}
}

void my_kill(char mine[wide+2][long+2])          //布雷
{
	for (int i = 0; i < kills;)
	{
		int x = rand() % wide+1;
		int y = rand() % long+1;
		if (mine[x][y] != '*')
		{
			mine[x][y] = '*';
			i++;
		}
	}
	//my_print(mine);
}



int my_player(char mine[wide+2][long+2], char show[wide][long])
{
	int x = 0, y = 0;
	printf("请输入你要选择的位置：\n>>> ");
	scanf("%d%d",&x,&y);
	if (mine[x][y] == '*')
	{
		printf("\n踩雷了，游戏结束\n");
		return 0;
	}
	else
	{
		show[x - 1][y - 1] = 0;
		my_print(show);
		printf("请继续游戏\n");
		my_check(mine,x,y);
		return 1;
	}

	if (my_decide(show))
	{
		printf("\n已扫除全部雷，扫雷结束\n");
		return 0;
	}
}

int my_decide(char show[wide][long])
{
	int num = 0;
	for (int i = 0; i < wide; i++)
	{
		for (int j = 0; j<long; j++)
		{
			if (show[i][j] == 0)
			{
				num++;
			}
		}
	}
	if (num == wide * long - kills)
	{
		return 1;
	}
	return 0;
}


//void my_check(char mine[wide][long],int x,int y)
//{
//	int sum = 0;
//	if (x <= wide - 2 && x >= 1 && y <= long - 2 && y >= 1)
//	{
//		if (mine[x - 1][y - 1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x - 1][y ] == '*')
//		{
//			sum++;
//		}
//		if (mine[x - 1][y +1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x][y+1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x][y - 1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x +1][y - 1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x +1][y +1] == '*')
//		{
//			sum++;
//		}
//		if (mine[x +1][y] == '*')
//		{
//			sum++;
//		}
//	}
//	if(x==0&&y==0)     
//	//   舍弃  ，这样计数太麻烦
//
//}

void my_check(char mine[wide+2][long+2], int x, int y)
{
	int sum = 0;
		if (mine[x - 1][y - 1] == '*')
		{
			sum++;
		}
		if (mine[x - 1][y ] == '*')
		{
			sum++;
		}
		if (mine[x - 1][y +1] == '*')
		{
			sum++;
		}
		if (mine[x][y+1] == '*')
		{
			sum++;
		}
		if (mine[x][y - 1] == '*')
		{
			sum++;
		}
		if (mine[x +1][y - 1] == '*')
		{
			sum++;
		}
		if (mine[x +1][y +1] == '*')
		{
			sum++;
		}
		if (mine[x +1][y] == '*')
		{
			sum++;
		}
		printf("周围一共有%d个雷\n",sum);
}
