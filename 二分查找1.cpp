#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
void readvector(vector<int>& x);
void show(vector<int>& x, int n);
int findnum(vector<int>& x, int lo, int hi, int n);
int sum = 0;
int main() {
	vector<int> x;
	readvector(x);
	//show(x, x.size());
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 10000; i++) {
		cout << i << "  " << findnum(x, 0, x.size() - 1, i) << endl;
	}
	cout << sum << "´Î" << endl;
	end = clock();
	cout << end - start << "ms" << endl;
	return 0;
}

void readvector(vector<int>& x) {
	ifstream fin("123.txt");
	int temp;
	while (!fin.eof()) {
		fin >> temp;
		x.push_back(temp);
	}
}

void show(vector<int>& x, int n) {
	cout << "size:" << n << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
		if ((i + 1) % 30 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

int findnum(vector<int>& x, int lo, int hi, int n) {
	int mi;
	while (lo < hi) {
		sum++;
		//cout << lo << " " << hi << endl;
		mi = (lo + hi) >> 1;
		if (x[mi] > n)
			hi = mi;
		else if (x[mi] < n)
			lo = mi + 1;
		else
			return mi;
	}
	return -1;
}