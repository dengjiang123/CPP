#include<iostream>
#include<fstream>
using namespace std;
string filename = "123.txt";
int count_row(string name);
void read_data(double** p, string name, int n);
double lagrange(double** p, int n, double x);
int main() {
	int n;
	n = count_row(filename);
	double** p = new double* [2];
	p[0] = new double[n];
	p[1] = new double[n];
	read_data(p, filename, n);

	double t = lagrange(p, n, 3.5);
	cout << t << endl;

}

int count_row(string name) {
	ifstream fin(name);
	int n = 0;
	int temp;
	while (!fin.eof()) {
		fin >> temp;
		n++;
	}
	fin.close();
	return n / 2;
}

void read_data(double** p, string name, int n) {
	ifstream fin(name);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			fin >> p[i][j];
		}
	}
	fin.close();
}

double lagrange(double** p, int n, double x) {
	double sum = 0;
	double temp = 1;
	for (int i = 0; i < n; i++) {
		temp = p[1][i];
		for (int j = 0; j < n; j++) {
			if (i != j) {
				temp *= (((x - p[0][j]) / (p[0][i] - p[0][j])));
			}
		}
		sum += temp;
	}
	return sum;
}