#include<iostream>
int judge(int n);
void fac(int n);
using namespace std;
int main() {
	int n;
	cin >> n;
	fac(n);
	return 0;
}

void fac(int n) {
	int i;
	if (judge(n)) {
		cout << n;
	}
	else {
		for (i = 2; i <= n / 2; i++) {
			if (judge(i) && n % i == 0) {
				cout << i << " ";
				break;
			}
		}
		if (judge(n / i) == 0) {
			fac(n / i);
		}
		else {
			cout << n / i;
		}
	}
}

int judge(int n) {
	if (n == 2 || n == 3) {
		return 1;
	}
	else{
		int f = 1;
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				f = 0;
			}
		}
		return f;
	}
}