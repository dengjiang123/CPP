#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[])
{
    int flag = 0;
    char passwd[10];
    memset(passwd, 'a', sizeof(passwd));
    printf("%s\n", passwd);
    strcpy(passwd, argv[1]);

    if (0 == strcmp("apple", passwd))
    {
        flag = 1;
    }

    if (flag)
        printf("\n Password cracked \n");
    else
        printf("\n Incorrect passwd \n");
    return 0;
}