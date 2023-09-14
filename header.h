#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 15

/**
 * struct User: structure of user data
 * username: Name of the use to create the account
 * password: To store password of the user
 */
typedef struct User {
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	struct User *next;
} User;
extern User *head;

int login(User **head, const char *username, const char *password);
int login_or_AddUser(int num);
int NewUser(User **head, const char *name, const char *password);
size_t printusers(User *head);
#endif/*header defined for bank managemnt system*/
