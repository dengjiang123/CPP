#include<iostream>
using namespace std;
void show(int* p, int n);
void reverse(int* p, int lo, int hi);
int main() {
	int* p = new int[99];
	for (int i = 0; i < 99; i++) {
		p[i] = i + 1;
	}
	reverse(p, 0, 98);
	show(p, 99);
}

void show(int* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl << endl;
}

void reverse(int* p, int lo, int hi) {
	int temp;
	if (lo < hi) {
		temp = p[lo];
		p[lo] = p[hi];
		p[hi] = temp;
		reverse(p, lo + 1, hi - 1);
	}
}