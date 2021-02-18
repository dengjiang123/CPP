#include<iostream>
#include<random>
#include<ctime>
#include"aaa.h"

np::np(int a, int b) {
	this->m = a;
	this->n = b;
	p = new double* [a];
	for (int i = 0; i < a; i++) {
		p[i] = new double[b];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			p[i][j] = 0;
		}
	}
}

void np::random_np(int low, int hig) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = rand() % (hig - low) + low;
		}
	}
}

void np::show_np() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int np::rank_np() {
	double temp;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			temp = -p[j][i] / p[i][i];
			for (int k = i; k <= n; k++) {
				p[j][k] += temp * p[i][k];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		temp = p[i][i];
		for (int j = i; j < n; j++) {
			p[i][j] = p[i][j] / temp;
			}
		}
	return 0;
}

np np::dot(np B) {
	np C(m, B.n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < B.n; j++) {
			for (int k = 0; k < n; k++) {
				C.p[i][j] += (p[i][k] * B.p[k][j]);
			}
		}
	}
	return C;
}