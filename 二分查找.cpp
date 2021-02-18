#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
void show(vector<int>& x, int n);
int search(vector<int>& x, int lo, int hi, int find);
int sum = 0;
int main() {
	vector<int> x;
	ifstream fin("123.txt");
	int temp;
	while (!fin.eof()) {
		fin >> temp;
		x.push_back(temp);
	}
	//show(x, x.size());
	int answer;
	//answer = search(x, 0, x.size(), 1138);
	for (int i = 1; i <= 10000; i++) {
		answer = search(x, 0, x.size(), i);
		cout << i << " " << answer << endl;
	}
	cout << sum / 100;
	return 0;
}

void show(vector<int>& x, int n) {
	cout << n << "####:" << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
		if ((i + 1) % 30 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

int search(vector<int>& x, int lo, int hi, int find) {
	int mi;
	while (lo < hi) {
		//cout << lo << " " << hi << endl;
		mi = (lo + hi) >> 1;
		if (find < x[mi])
			hi = mi;
		else if (find > x[mi])
			lo = mi + 1;
		else
			return mi;
	}
	return -1;
}