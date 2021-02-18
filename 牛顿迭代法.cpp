#include<iostream>
double fac(int a, int b, int c, int d, double x);
double fac2(int a, int b, int c, int d, double x);
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double x1=1.5,x2,t;
	x2 = x1 - fac(a,b,c,d,x1) / fac2(a,b,c,d,x1);
	while ((x1 - x2 < -1.0E-10 )|| (x1 - x2 > 1.0E-10)) {
		x2 = x1 - fac(a, b, c, d, x1) / fac2(a, b, c, d, x1);
		t = x1;
		x1 = x2;
		x2 = t;
	}
	cout << x2 << endl;
	cout << a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d << endl;
	return 0;
}

double fac(int a, int b, int c, int d, double x) {
	double s;
	s = a * x * x * x + b * x * x + c * x + d;
	return s;
}

double fac2(int a, int b, int c, int d, double x) {
	double s;
	s = 3 * a * x * x + 2 * b * x + c;
	return s;
}