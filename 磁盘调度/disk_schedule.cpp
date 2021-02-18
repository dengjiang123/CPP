#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
using namespace std;
void show(vector<int> x, int n);
void write_file(vector<int> x, int n);
int main() {
	int n;
	int temp;
	n = 100;
	vector<int> x;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		temp = rand() % 200;
		x.push_back(temp);
	}
	show(x, x.size());
	write_file(x, x.size());
	return 0;
}

void show(vector<int> x, int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
		if ((i + 1) % 15 == 0) {
			cout << endl;
		}
	}
}

void write_file(vector<int> x, int n) {
	ofstream fout("temp.txt");
	for (int i = 0; i < n; i++) {
		fout << x[i] << " ";
		if ((i + 1) % 15 == 0) {
			fout << endl;
		}
	}
}