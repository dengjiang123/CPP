#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
void show(vector<int>& x, int n);
int main() {
	int n;
	n = 10000;
	vector<int> x;
	srand(time(0));
	for (int i = 1; i <= n; i++) {
		x.push_back(rand() % 10000);
	}
	random_shuffle(x.begin(), x.end());
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	show(x, x.size());
}

void show(vector<int>& x, int n) {
	cout << "size:" << n << endl;
	ofstream out("123.txt");
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
		out << x[i] << " ";
		if ((i + 1) % 30 == 0) {
			cout << endl;
			out << endl;
		}
	}
	cout << endl;
}