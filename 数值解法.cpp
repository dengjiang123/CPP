#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
double f(double x, double y);
double F(double x);
void show(vector<double>& x);

void original(vector<double>& x, vector<double>& y);
void euler(vector<double>& x, vector<double>& y);
void improve_euler(vector<double>& x, vector<double>& y);
void R_K(vector<double>& x, vector<double>& y);

void tolerance(vector<double>& x, vector<double>& y);

int main() {
	vector<double> x;
	for (int i = 0; i <= 10; i++) {
		x.push_back(0.1 * i);
	}
	vector<double> a;
	vector<double> b;
	vector<double> c;
	vector<double> d;
	original(x, a);
	euler(x, b);
	improve_euler(x, c);
	R_K(x, d);
	cout << "准确解:       ";
	show(a);

	cout << endl << "欧拉方法:     ";
	show(b);
	cout << "误差:         ";
	tolerance(a, b);

	cout << endl << "改进欧拉方法: ";
	show(c);
	cout << "误差:         ";
	tolerance(a, c);

	cout << endl << "R_K方法:      ";
	show(d);
	cout << "误差:         ";
	tolerance(a, d);

	return 0;
}

double f(double x, double y) {
	double sum = 0;
	sum = x * 2 / (3 * y * y);
	return sum;
}

double F(double x) {
	double sum = 0;
	sum = pow(1 + x * x, 1.0 / 3);
	return sum;
}

void show(vector<double>& x) {
	int n = x.size();
	for (int i = 0; i < n; i++) {
		cout << setw(12);
		cout << fixed << setprecision(8) << x[i];
	}
	cout << endl;
}

void original(vector<double>& x, vector<double>& y) {
	int n = x.size();
	for (int i = 0; i < n; i++) {
		y.push_back(F(x[i]));
	}
}

void euler(vector<double>& x, vector<double>& y) {
	y.push_back(1.0);
	int n = x.size();
	for (int i = 1; i < n; i++) {
		y.push_back(y[i - 1] + 0.1 * f(x[i - 1], y[i - 1]));
	}
}

void improve_euler(vector<double>& x, vector<double>& y) {
	y.push_back(1.0);
	int n = x.size();
	for (int i = 1; i < n; i++) {
		y.push_back(y[i - 1] + 0.05 * (f(x[i - 1], y[i - 1]) + f(x[i], y[i - 1] + 0.1 * f(x[i - 1], y[i - 1]))));
	}
}

void R_K(vector<double>& x, vector<double>& y) {
	y.push_back(1.0);
	int n = x.size();
	double k1, k2, k3, k4, sum;
	for (int i = 1; i < n; i++) {
		k1 = f(x[i - 1], y[i - 1]);
		k2 = f(x[i - 1] + 0.1 / 2, y[i - 1] + 0.1 / 2 * k1);
		k3 = f(x[i - 1] + 0.1 / 2, y[i - 1] + 0.1 / 2 * k2);
		k4 = f(x[i - 1] + 0.1, y[i - 1] + 0.1 * k3);
		sum = y[i - 1] + 0.1 * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y.push_back(sum);
	}
}

void tolerance(vector<double>& x, vector<double>& y) {
	int n = x.size();
	for (int i = 0; i < n; i++) {
		cout << setw(12);
		cout << fixed << setprecision(8) << y[i] - x[i];
	}
	cout << endl;
}