#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("COMSPEC"));
    printf("ROOT : %s\n", getenv("HOME"));
}