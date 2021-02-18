#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int count_line();
void read_mat(double** p, int n);  //建立文件123.txt，将系数写入文件，read_mat函数读取数据
void show_mat(double** p, int m, int n);
void jacobi(double** p, int n);
void guass(double** p, int n);
void sor(double** p, int n, double w);
double judge(double* x, double* t, int n);

double e = 0.0001;
int main() {
	int n;
	n = count_line();
	double** p = new double* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new double[n + 1];
	}
	read_mat(p, n);
	show_mat(p, n, n + 1);
	jacobi(p, n);
	guass(p, n);
	sor(p, n, 1.334);
	sor(p, n, 1.95);
	sor(p, n, 0.95);
}

int count_line() {
	int n;
	n = 0;
	ifstream fin("123.txt");
	string temp;
	while (getline(fin, temp)) {
		n++;
	}
	fin.close();
	return n;
}

void read_mat(double** p, int n) {
	ifstream fin("123.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			fin >> p[i][j];
		}
	}
	fin.close();
}

void show_mat(double** p, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout.setf(ios::fixed);
			cout << setiosflags(ios::fixed) << setprecision(4) << setw(10) << p[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void jacobi(double** p, int n) {
	cout << "雅可比迭代法：" << endl;
	int count = 0;
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	double* t = new double[n];
	while (1) {
		count++;
		for (int i = 0; i < n; i++) {
			t[i] = p[i][n];
			for (int j = 0; j < n; j++) {
				if (i != j) {
					t[i] -= p[i][j] * x[j];
				}
			}
			t[i] /= p[i][i];
		}
		if (judge(x, t, n) < e) {
			break;
		}
		for (int k = 0; k < n; k++) {
			x[k] = t[k];
		}
	}
	cout << "方程解:" << endl;
	for (int i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << setiosflags(ios::fixed) << setprecision(15) << setw(18) << t[i];
	}
	cout << endl << "迭代次数:" << count << endl << endl;
}

void guass(double** p, int n) {
	cout << "高斯—赛德尔：" << endl;
	int count = 0;
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	double* t = new double[n];
	while (1) {
		count++;
		for (int i = 0; i < n; i++) {
			t[i] = p[i][n];
			for (int j = 0; j < n; j++) {
				if (i > j) {
					t[i] -= p[i][j] * t[j];
				}
				else if (i < j) {
					t[i] -= p[i][j] * x[j];
				}
			}
			t[i] /= p[i][i];
		}
		if (judge(x, t, n) < e) {
			break;
		}
		for (int k = 0; k < n; k++) {
			x[k] = t[k];
		}
	}
	cout << "方程解:" << endl;
	for (int i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << setiosflags(ios::fixed) << setprecision(15) << setw(18) << t[i];
	}
	cout << endl << "迭代次数:" << count << endl << endl;
}

void sor(double** p, int n, double w) {
	cout << "SOR迭代法：" << endl;
	cout << "w=" << w << endl;
	int count = 0;
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	double* t = new double[n];
	while (1) {
		count++;
		for (int i = 0; i < n; i++) {
			t[i] = p[i][n];
			for (int j = 0; j < n; j++) {
				if (i > j) {
					t[i] -= p[i][j] * t[j];
				}
				else if (i < j) {
					t[i] -= p[i][j] * x[j];
				}
			}
			t[i] = w * t[i] + (1 - w) * x[i] * p[i][i];
			t[i] /= p[i][i];
		}
		if (judge(x, t, n) < e) {
			break;
		}
		for (int k = 0; k < n; k++) {
			x[k] = t[k];
		}
	}
	cout << "方程解:" << endl;
	for (int i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << setiosflags(ios::fixed) << setprecision(15) << setw(18) << t[i];
	}
	cout << endl << "迭代次数:" << count << endl << endl;
}

double judge(double* x, double* t, int n) {
	double e;
	double temp = 0;
	for (int i = 0; i < n; i++) {
		temp = temp + pow((x[i] - t[i]), 2);
	}
	e = sqrt(temp);
	return e;
}