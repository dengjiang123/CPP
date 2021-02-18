#include<iostream>
#include<ctime>
using namespace std;
int fac(int n);
int main() {
	clock_t start, end;
	start = clock();
	//for(int i=1;i<=40;i++)
	cout << fac(40) << endl;
	end = clock();
	cout << end - start << endl;
	return 0;
}

int fac(int n) {
	if (n <= 1)
		return n;
	else
		return fac(n - 1) + fac(n - 2);
}