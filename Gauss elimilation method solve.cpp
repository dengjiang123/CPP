#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int count_line();
void read_mat(double** p, int n);
void show_mat(double** p, int n);
void move_mat(double** p, int s, int n);
void simplify_mat1(double** p, int n);
double* solve_mat(double** p, int n);
void show_solve(double* t, int n);
void simplify1_mat1(double** p, int n);
int main() {
	int n;
	n = count_line();

	double** p = new double* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new double[n + 1];
	}
	cout << "顺序消元法:" << endl;
	read_mat(p, n);
	simplify_mat1(p, n);
	show_mat(p, n);
	double* t = new double[n];
	t = solve_mat(p, n);
	show_solve(t, n);


	double** p1 = new double* [n];
	for (int i = 0; i < n; i++) {
		p1[i] = new double[n + 1];
	}
	cout << "列主元消元法:" << endl;
	read_mat(p1, n);
	simplify1_mat1(p1, n);
	show_mat(p1, n);
	double* t1 = new double[n];
	t1 = solve_mat(p1, n);
	show_solve(t1, n);

	cout << scientific << t[0] - t1[0] << endl;
	return 0;
}

int count_line() {
	int n = 0;
	string line;
	ifstream fin("123.txt");
	while (getline(fin, line)) {
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

void show_mat(double** p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			cout.setf(ios::fixed);
			cout << setiosflags(ios::fixed) << setprecision(4) << setw(10) << p[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void move_mat(double** p, int s, int n) {
	double t;
	for (int i = s + 1; i < n; i++) {
		if (fabs(p[s][s]) < fabs(p[i][s])) {
			for (int j = 0; j <= n; j++) {
				t = p[s][j];
				p[s][j] = p[i][j];
				p[i][j] = t;
			}
		}
	}
}

void simplify_mat1(double** p, int n) {
	double t;
	for (int i = 0; i < n; i++) {
		//move_mat(p, i, n);
		for (int j = i + 1; j < n; j++) {
			t = -p[j][i] / p[i][i];
			for (int k = i; k <= n; k++) {
				p[j][k] += t * p[i][k];
			}
			//show_mat(p, n);
		}
	}
}

void simplify1_mat1(double** p, int n) {
	double t;
	for (int i = 0; i < n; i++) {
		move_mat(p, i, n);
		for (int j = i + 1; j < n; j++) {
			t = -p[j][i] / p[i][i];
			for (int k = i; k <= n; k++) {
				p[j][k] += t * p[i][k];
			}
			//show_mat(p, n);
		}
	}
}


double* solve_mat(double** p, int n) {
	double* t = new double[n];
	double sum;
	for (int i = n - 1; i >= 0; i--) {
		sum = p[i][n];
		for (int j = n - 1; j > i; j--) {
			sum -= p[i][j] * t[j];
		}
		t[i] = sum / p[i][i];
	}
	return t;
}

void show_solve(double* t, int n) {
	for (int i = 0; i < n; i++) {
		cout.setf(ios::fixed);
		cout << setprecision(10) << setw(20) << t[i];
	}
	cout << endl;
}