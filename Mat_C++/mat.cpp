#include"mat.h"
#include<iomanip>

Mat::Mat(int row, int col) {
	this->row = row;
	this->col = col;
	M = new double* [row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = 0;
	}
}

Mat::Mat(const Mat& ori) {
	row = ori.row;
	col = ori.col;
	M = new double* [row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = ori.M[i][j];
	}
}

Mat::~Mat() {
	for (int i = 0; i < row; i++)
		delete[] M[i];
	delete M;
	//std::cout << "HHHHHH" << std::endl;
}

void Mat::operator=(const Mat& A) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			delete[] M[i];
	delete M;
	row = A.row;
	col = A.col;
	M = new double* [row];
	for (int i = 0; i < row; i++) {
		M[i] = new double[col];
		for (int j = 0; j < col; j++)
			M[i][j] = A.M[i][j];
	}
}

Mat Mat::operator*(const Mat& A) {
	if (col != A.row) {
		std::cout << "Wrong! Couldn't Miltiply!\n";
		return Mat(0, 0);
	}
	Mat last(row, A.col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < A.col; j++)
			for (int k = 0; k < col; k++)
				last.M[i][j] += (M[i][k] * A.M[k][j]);
	return last;
}

Mat Mat::operator-(const Mat& A) {
	if (row != A.row || col != A.col) {
		std::cout << "Wrong! Couldn't Subtraction!\n";
		return Mat(0, 0);
	}
	Mat last(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < A.col; j++)
			last.M[i][j] = this->M[i][j] - A.M[i][j];
	return last;
}

Mat Mat::operator+(const Mat& A) {
	if (row != A.row || col != A.col) {
		std::cout << "Wrong! Couldn't Addition!\n";
		return Mat(0, 0);
	}
	Mat last(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < A.col; j++)
			last.M[i][j] = this->M[i][j] + A.M[i][j];
	return last;
}

void Mat::Show_M() {
	std::cout << std::endl << "Print M:\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			std::cout << M[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Mat::Initial() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			std::cin >> M[i][j];
}

ostream& operator<<(ostream& os, const Mat& A) {
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++)
			std::cout << std::setw(6) << A.M[i][j] << " ";
		std::cout << std::endl;
	}
	return os;
}