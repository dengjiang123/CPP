#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
void hanio(int n, vector<int>& x, vector<int>& y, vector<int>& z);
void show(vector<int>& x, vector<int>& y, vector<int>& z);
int sum = 0;
int main() {
	int n;
	vector<int> x, y, z;
	cin >> n;
	clock_t start, end;
	start = clock();
	for (int i = 1; i <= n; i++) {
		x.push_back(n + 1 - i);
	}
	hanio(n, x, y, z);
	cout << sum << endl;
	end = clock();
	cout << end - start << endl;
	return 0;
}

void hanio(int n, vector<int>& x, vector<int>& y, vector<int>& z) {
	if (n == 1) {
		z.push_back(x[x.size() - 1]);
		x.pop_back();
	}
	else {
		hanio(n - 1, x, z, y);
		z.push_back(x[x.size() - 1]);
		x.pop_back();
		hanio(n - 1, y, x, z);
	}
	sum++;
	//show(x, y, z);
}

void show(vector<int>& x, vector<int>& y, vector<int>& z) {
	cout << "X: ";
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	cout << "Y: ";
	for (int i = 0; i < y.size(); i++) {
		cout << y[i] << " ";
	}
	cout << endl;

	cout << "Z: ";
	for (int i = 0; i < z.size(); i++) {
		cout << z[i] << " ";
	}
	cout << endl;
	cout << endl;
}