#include<iostream>
using namespace std;
int fac(int n, int& temp);
int f(int n);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cout << f(i) << endl;
	}
}

int f(int n) {
	int ptemp;
	return fac(n, ptemp);
}

int fac(int n, int& temp) {
	if (n == 0) {
		temp = 1;
		return 0;
	}
	else {
		int ptemp;
		temp = fac(n - 1, ptemp);
		return temp + ptemp;
	}
}