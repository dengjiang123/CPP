#include<iostream>
#include"mat.h"
using namespace std;
int main() {
	Mat A(7, 7);
	A.Initial();
	Mat B(7, 7);
	B.Initial();
	//Mat C = A * B;
	A.Show_M();
	B.Show_M();
	//C.Show_M();
	cout << A * B << endl;
	A = B;
	cout << A << endl;
}