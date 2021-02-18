#include<iostream>
#include<vector>
using namespace std;
void getfac(vector<int>& x, int n);
void show(vector<int>& x, int n);
int fac(int n, int& temp);
int f(int n);
int main() {
	int n;
	n = 100000;
	vector<int> x;
	getfac(x, n);
	show(x, x.size());
	cout << x[x.size() - 2];;
	return 0;
}

void getfac(vector<int>& x, int n) {
	int temp = 0;
	x.push_back(0);
	x[temp] = 1;
	while (x[temp] < n) {
		temp++;
		x.push_back(f(temp + 1));
	}
	x.pop_back();
}

void show(vector<int>& x, int n) {
	cout << "size:" << n << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ,";
	}
	cout << endl;
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

int f(int n) {
	int ptemp;
	return fac(n, ptemp);
}