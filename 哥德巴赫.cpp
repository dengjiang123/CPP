#include<iostream>
#include<ctime>
int fac(int n);
using namespace std;
int main() {
	clock_t start, end;
	int n;
	cin >> n;
	start = clock();
	int f;
	int m;
	for (int i = 4; i <= n; i += 2) {
		f = 0;
		if (i == 4) {
			f = 1;
		}
		else {
			for (m = 3; m <= i / 2; m += 2) {
				if (fac(m) && fac(i - m)) {
					f = 1;
				}
				if (f) {
					break;
				}
			}
		}
		if (f==0) {
			cout << i << endl;
		}
	}
	end = clock();
	cout << end - start;
	return 0;
}

int fac(int n) {
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	else if (n == 4) {
		return 0;
	}
	else {
		int i = 3;
		int f = 1;
		for (i = 3; i <= n / 2; i++) {
			if (n % i == 0) {
				f = 0;
			}
		}
		return f;
	}
}