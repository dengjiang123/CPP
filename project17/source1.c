#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void) {
	int flag = 0;
	char password[10];
	memset(password, 0, sizeof(password));
	printf("nEnter password: ");
	scanf("%s", password);
	if (0 == strcmp("abc", password))
		flag = 1;
	if (flag)
		printf("Password cracked!\n");//ÃÜÂëÍ¨¹ı 
	else
		printf("Please enter correct password!\n");//ÃÜÂë´íÎó 
	return 0;
}