#include<iostream>
#include<ctime>
using namespace std;
int fac(int n);
int main() {
	int n;
	cin >> n;
	clock_t a, b;
	a = clock();
	for (int i = 0;i <= n;i++) {
		cout << i << " " << fac(i) << endl;
	}
	b = clock();
	cout << b - a << endl;
	system("pause");
	return 0;
}

int fac(int n) {
	if (n < 2) {
		return n;
	}
	else {
		return fac(n - 1) + fac(n - 2);
	}
}