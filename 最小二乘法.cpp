#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
void read(double* x, double* y);
void show(double* x);
void to_mat(double** A, double* x, double* y);
double get_value(double* x, double* y, int i, int j);
double judge(double* x, double* t, int n);
void guass(double** p, int n);
const int sizet = 9;
const double e = 0.0000000001;
int main() {
	double* x = new double[sizet];
	double* y = new double[sizet];
	read(x, y);
	cout << "读入原始数据:" << endl;
	show(x);
	show(y);
	cout << endl;
	double** A = new  double* [3];
	for (int i = 0; i < 3; i++) {
		A[i] = new double[4];
	}
	to_mat(A, x, y);
	cout << "A的矩阵:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	guass(A, 3);
}

void read(double* x, double* y) {
	ifstream fin("123.txt");
	double temp;
	for (int i = 0; i < sizet; i++) {
		fin >> temp;
		x[i] = temp;
	}
	for (int i = 0; i < sizet; i++) {
		fin >> temp;
		y[i] = temp;
	}
	fin.close();
}

void show(double* x) {
	for (int i = 0; i < sizet; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void to_mat(double** A, double* x, double* y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = get_value(x, y, i, j);
		}
	}
}

double get_value(double* x, double* y, int i, int j) {
	double sum = 0;
	double temp = 1;
	if (j < 3) {
		for (int m = 0; m < sizet; m++) {
			temp = 1;
			for (int n = 0; n < i + j; n++) {
				temp *= x[m];
			}
			sum += temp;
		}
	}
	else {
		for (int m = 0; m < sizet; m++) {
			temp = 1;
			for (int n = 0; n < i ; n++) {
				temp *= x[m];
			}
			temp *= y[m];
			sum += temp;
		}
	}
	//cout << i << " " << j << " " << sum << endl;
	return sum;
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
		cout << setiosflags(ios::fixed) << setprecision(12) << setw(18) << t[i];
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