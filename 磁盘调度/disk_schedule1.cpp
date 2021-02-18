#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

void read_file(vector<int>& x);
void show(vector<int> x, int n);
int sumscan(vector<int> x, int n);
int main() {
	vector<int> x;
	read_file(x);
	//show(x, x.size());
	int sum1 = sumscan(x, x.size());
	cout << "sum1: " << sum1 << endl;
	sort(x.begin(), x.end());
	int sum2 = sumscan(x, x.size());
	cout << "sum2: " << sum2 << endl;
	show(x, x.size());
	return 0;
}

int sumscan(vector<int> x, int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += fabs(x[i] - x[i - 1]);
	}
	return sum;
}

void read_file(vector<int>& x) {
	ifstream fin("temp.txt");
	int temp;
	while (!fin.eof()) {
		fin >> temp;
		x.push_back(temp);
	}
	fin.close();
}

void show(vector<int> x, int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
		if ((i + 1) % 15 == 0) {
			cout << endl;
		}
	}
}