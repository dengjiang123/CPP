#include<iostream>
using std::ostream;
using std::istream;

class Mat {
private:
	int row;
	int col;
	double** M;
public:
	Mat(int row, int col);
	Mat(const Mat& ori);
	~Mat();

	void Initial();
	void operator=(const Mat& A);
	Mat operator*(const Mat& A);
	Mat operator-(const Mat& A);
	Mat operator+(const Mat& A);

	void Show_M();

	friend ostream& operator<<(ostream& os, const Mat& A);
};