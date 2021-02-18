//filefunc.cpp -- function with ostream & parameter
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//函数原型：无返回值，该函数含有4个参数，分别是ostream类型的引用变量作为参数
//double类型的值作为参数，double类型的数组作为参数，int类型的值作为参数。
//根据参数的类型可知，在调用此函数时应使用1.ostream类型的原始变量 2.double
//类型的变量，3.double类型的数组首地址 4.int类型的值作为实际参数传递
void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	//声明定义了ofstream类型的变量fout；
	ofstream fout;
	//定义指向char类型的常量指针并为其赋值
	const char* fn = "ep-data.txt";
	//
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your "
		"telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths, in mm, of " << LIMIT
		<< " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	//文件打开对象、对象细节、数组名、数组长度作为参数传递
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "Done\n";
	// cin.get();
	// cin.get();
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	// save initial formatting state
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize sz = os.precision(0);
	os << "Focal length of objective: " << fo << " mm\n";
	os.precision(1);
	os.width(12);
	os << "f.l. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	// restore initial formatting state
	os.setf(initial, ios_base::floatfield);
	os.precision(sz);
}

