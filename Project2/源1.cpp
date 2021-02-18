#include<iostream>
#include"aaa.h"
int main() {
	int m, n;
	std::cout << "Êä³ö¾ØÕó¹æÄ£: ";
	std::cin >> m >> n;
	np A(m, n);
	np B(m, n);
	A.random_np(10, 100);
	B.random_np(10, 100);
	A.show_np();
	B.show_np();
	(A.dot(B)).show_np();
}