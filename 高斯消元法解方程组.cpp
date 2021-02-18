#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
	int n=0;
	ifstream fin("123.txt", ios::in);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		n++;
	}
	fin.close();

	double** p = new double* [n];
	for (int i = 0; i <= n; i++) {
		p[i] = new double[n + 1];
	}

	ifstream re("123.txt");
	double a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			re >> a;
			p[i][j] = a;
		}
	}

	double t;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			t = -p[j][i] / p[i][i];
			for (int k = i; k <= n; k++) {
				p[j][k] += t * p[i][k];
			}
		}
	}

	double b;
	double* an = new double[n];
	for (int i = n-1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			b = -p[j][i] / p[i][i];
			for (int k = n; k >= i; k--) {
				p[j][k] += b * p[i][k];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout.setf(ios::fixed);
			cout << setprecision(3) << setiosflags(ios::right) << setw(10) << p[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		an[i] = p[i][n] / p[i][i];
	}

	
	for (int i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << setprecision(6) << setw(12) << an[i];
	}
	return 0;
}