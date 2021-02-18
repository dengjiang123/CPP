#include<iostream>
#include<string>
#include"brass.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	BrassPlus test("Horation Hogg", 382288, 3000.0);
	Brass* p;
	p = &test;
	p->ViewAcct();
	cout << endl;
	Brass a = test;
	a.ViewAcct();
	cout << endl;
	return 0;
}