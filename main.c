#include "header.h"
/**
 * main - first interface for the user
 * Return: return 0 always success
 */
int main(void)
{
	int num;

	while(1)
	{
		
		printf("\n\n\t WELCOME TO UNIARFIQ BANK MANAGEMENT SYSTEM\n");
		printf("\033[8m");

		printf("\n\n\n\t Select operation to continue\n");

		printf("\n\t1. Login\n\n\t2. Add User\n\n\t3. EXIT\n");

		scanf("%d", &num);

		if (num == 1)
		{
			printf("loading Login portal\n");
			system("clear");
			sleep(3);
			login_or_AddUser(num);
			break;
		}
		else if (num == 2)
		{
			printf("Loading User portal\n");
			system("clear");
			sleep(3);
			login_or_AddUser(num);
			break;
		}
		else if (num == 3)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Wrong input");
		}
	}
	return (0);
}
