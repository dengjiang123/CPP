#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;
double pi = atan(1) * 4;
double e = 0.0001;

double f(double x);
double get_x(double n, double i);       //获取x轴序列
void show(const vector<double>& x);     //输出T,S,C,R序列
double sum_X(const vector<double>& x);  //获得四分之一周长


int main() {
	vector<double> X;
	vector<double> T;
	vector<double> S;
	vector<double> C;
	vector<double> R;
	int n = 1;
	while (1) {
		for (int i = 0; i <= n; i++) {
			if (i < X.size()) {
				X[i] = f(get_x(n, i));
			}
			else {
				X.push_back(f(get_x(n, i)));
			}
		}
		//show(X);
		T.push_back(sum_X(X));
		n *= 2;
		if (T.size() >= 2) {
			S.push_back(4.0 / 3 * T[T.size() - 1] - 1.0 / 3 * T[T.size() - 2]);
		}
		if (S.size() >= 2) {
			C.push_back(16.0 / 15 * S[S.size() - 1] - 1.0 / 15 * S[S.size() - 2]);
		}
		if (C.size() >= 2) {
			R.push_back(64.0 / 63 * C[C.size() - 1] - 1.0 / 63 * C[C.size() - 2]);
		}
		if (R.size() >= 2 && fabs(R[R.size() - 1] - R[R.size() - 2]) < e) {
			break;
		}
	}
	//show(X);
	show(T);
	show(S);
	show(C);
	show(R);
	cout << setprecision(15);
	cout << "椭圆的周长为: " << 40 * R[R.size() - 1] << endl;
	return 0;
}

double sum_X(const vector<double>& x) {
	double sum = 0;
	int n = x.size();
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			sum += x[i];
		}
		else {
			sum += (2 * x[i]);
		}
	}
	sum = sum * ((pi / (n - 1)) / 4);
	return sum;
}

void show(const vector<double>& x) {
	int n = x.size();
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

double get_x(double n, double i) {
	double sum = 0;
	sum = pi / n * i;
	return sum / 2;
}

double f(double x) {
	double sum;
	sum = sqrt(1 + 3 * pow(sin(x), 2));
	return sum;
}