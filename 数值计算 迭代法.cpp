#include<iostream>
using namespace std;
double original(double x);
void erfenfa(double a, double b, double e);
double fiter(double x);
void iteration(double x, double e);
double oridao(double x);
double fnewton(double x);
void newton(double x,double e);
int main() {
	double a = 0, b = 1;
	double e = 0.0005;
	erfenfa(a, b, e);

	double x0 = 0;
	iteration(x0, e);

	newton(x0, e);
}

double original(double x) {
	return exp(x) + 10 * x - 2;
}

void erfenfa(double a,double b,double e) {
	double t;
	cout << "二分法迭代：" << endl;
	for (int i = 1; i <= 100; i++) {
		t = (a + b) / 2;
		if (original(a) * original(t) > 0) {
			a = t;
		}
		else {
			b = t;
		}
		if (fabs(a - b) < 2 * e) {
			cout << "二分法解:" << t << endl;
			cout << "二分迭代次数:" << i << endl << endl;
			break;
		}
		else if (i == 100) {
			cout << "wrong!" << endl;
		}
	}
}

double fiter(double x) {
	return (2 - exp(x)) / 10;
}

void iteration(double x, double e) {
	double t;
	cout << "迭代法：" << endl;
	for (int i = 1; i <= 100; i++) {
		t = fiter(x);
		if (t == x || fabs(t - x) < e) {
			cout << "迭代法解:" << x << endl;
			cout << "迭代次数:" << i-1 << endl << endl;
			break;
		}
		else if (i == 100) {
			cout << "wrong!" << endl;
		}
		x = t;
	}
}

double oridao(double x) {
	return exp(x) + 10;
}

double fnewton(double x) {
	return x - original(x) / oridao(x);
}

void newton(double x,double e) {
	double t;
	cout << "牛顿法：" << endl;
	for (int i = 1; i <= 100; i++) {
		t = fnewton(x);
		if (t == x || fabs(t - x) < e) {
			cout << "牛顿法解:" << x << endl;
			cout << "牛顿法次数:" << i-1 << endl << endl;
			break;
		}
		else if (i == 100) {
			cout << "wrong!" << endl;
		}
		x = t;
	}
}