#include "header.h"
/**
 * login_or_AddUser - function that returns a function for login
 * or AddUser operation
 * @num: input integer
 * Return: 1 if success or 0 if otherwise
 */
User *head = NULL;

int login_or_AddUser(int num)
{
	char name[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	char word[MAX_PASSWORD_LENGTH];
	int n, i, choice, x;

	printf("\n\n\t Enter UserName\n");
	scanf("%49s", name);
	getchar();
	printf("\n\n\t Enter password\n");
	scanf("%14s", password);
	getchar();
	printf("\n\n\tConfirm password\n");
	scanf("%14s", word);
	getchar();

	if (strcmp(password, word) == 0)
	{
		if (num == 1)
		{
			n = login(&head, name, password);
			if (n == 1)
			{
				printf("x\n");
			}
			else if (n == 0)
			{
				printf("\n\n\there are the users\n");
				printusers(head);
			}
		}
		else if (num == 2)
		{
			i = NewUser(&head, name, password);
			if (i == 1)
			{
				printf("New user add successfully\n");
				printf("\n\n\t 1. Login \n\n\t 2. Exit\n");
			}
			scanf("%d", &choice);
			if (choice == 1)
			{
				if (x = login(&head, name, password) == 1)
				{
					printf("x\n");
				}
			}
			else if (choice == 2)
			{
				exit(EXIT_FAILURE);
			}

		}
	}
	else
	{
		printf("password does not match\n");
		return (0);
	}
	return (0);
}



/**
 * NweUset - function that adds a new user
 * @name: name of the user
 * @head: points to the head node
 * @password: password
 * Return: return 1 when success and 0 when memory fails
 */
int NewUser(User **head, const char *name, const char *password)
{
	User *new_user;

	new_user = malloc(sizeof(User));
	if (new_user == NULL)
	{
		fprintf(stderr, "memory allocation failed\n");
		return (0);
	}
	strncpy(new_user->username, name, MAX_USERNAME_LENGTH - 1);
	new_user->username[MAX_USERNAME_LENGTH - 1] = '\0';

	strncpy(new_user->password, password, MAX_PASSWORD_LENGTH - 1);
	new_user->password[MAX_PASSWORD_LENGTH - 1] = '\0';

	if (*head == NULL)
	{
		*head = new_user;
	}

	new_user->next = *head;
	*head = new_user;

	return (1);
}



/**
 * login - function that creates login for user
 * &head: points to the head node
 * @username: points to the username provided
 * @password: points to the password provided
 * Return: return 1 if success or 0 if otherwise
 */
int login(User **head, const char *username, const char *password)
{
	User *current = *head;

	while (current)
	{
		if ((strcmp(username, current->username) == 0 && strcmp(password, current->password)) == 0)
		{
			printf("\n\n\t LOGIN SUCCESSFUL\n");
			return (1);
		}
		current = current->next;
	}
	printf("\n\n\t LOGIN FAILED\n");
	return (0);
}



/**
 * printusers - function that prints available users
 * @head: points to the head node
 * Return: returns the number of users
 *
 */
size_t printusers(User *head)
{
	User *current = head;
	size_t count = 0;

	while (current != NULL)
	{
		printf("%s\n \n%s\n", current->username, current->password);
		current = current->next;
		count++;
	}
	return (count);
}
