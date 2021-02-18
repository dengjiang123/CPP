#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
int fac(int n);
int main() {
	int n, i;
	clock_t start, end;
	scanf("%d", &n);
	start = clock();
	for (i = 1; i <= n; i++) {
		printf("%d %d\n", i, fac(i));
	}
	end = clock();
	printf("%d\n", end - start);
	return 0;
}

int fac(int n) {
	if (n <= 1)
		return n;
	else
		return fac(n - 1) + fac(n - 2);
}