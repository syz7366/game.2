#include"test.h"

int main()
{
	int start = 20;
	menu();
	scanf("%d",&start);
	srand(time(NULL));
	char show[long][wide] = { 0 };
	char mine[long+2][wide+2] = { 0 };       //布雷
	memset(show, '#', sizeof(show));
	my_print(show);
	switch (start)
	{
	case 1:
		my_kill(mine);   //放雷
		game(mine,show);
		my_print(mine);
		break;
	case 0:
		printf("\n游戏结束，欢迎下次再来!");
		break;
	}

	return 0;
}















