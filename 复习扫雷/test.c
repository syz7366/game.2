#include"test.h"

int main()
{
	int start = 20;
	menu();
	scanf("%d",&start);
	srand(time(NULL));
	char show[long][wide] = { 0 };
	char mine[long+2][wide+2] = { 0 };       //����
	memset(show, '#', sizeof(show));
	my_print(show);
	switch (start)
	{
	case 1:
		my_kill(mine);   //����
		game(mine,show);
		my_print(mine);
		break;
	case 0:
		printf("\n��Ϸ��������ӭ�´�����!");
		break;
	}

	return 0;
}















