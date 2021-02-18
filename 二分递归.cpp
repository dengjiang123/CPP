#include<iostream>
using namespace std;
int add(int* p, int i, int j);
int main() {
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 1; i <= n; i++) {
		p[i - 1] = i ;
	}
	int sum = 0;
	sum = add(p, 0, n - 1);
	cout << sum;
	return 0;
}

int add(int* p, int i, int j) {
	if (p[i] == p[j]) {
		return p[i];
	}
	else {
		int mi;
		mi = (i + j) / 2;
		return add(p, i, mi) + add(p, mi + 1, j);
	}
}