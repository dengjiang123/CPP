#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
void fac(string str);
int judge(int n);
ofstream f2("##answer##.txt");

int main(int argc, char** argv) {
	fstream file("12.txt", ios::out);
	file.close();
	system("dir /a /b *.txt >> 12.txt");
	ifstream f("12.txt");
	string str;
	
	int n = 0;
	while (!f.eof()) {
		//n++;
		//cout << n << endl;
		getline(f, str);
		//cout << str << endl;
		if (str.length() < 4) {
			break;
		}
		else if (str == "12.txt" || str == "##answer##.txt" || str=="123.txt") {
			//cout << "Yes" << endl;
		}
		else {
			fac(str);
		}
	}
	system("pause");
	return 0;
}

void fac(string str) {
	ifstream f(str);
	string temp;
	int n;
	while (!f.eof()) {
		f >> n;
		getline(f, temp);
		if (judge(n)) {
			f2 << n << temp << endl;
		}
	}
}

int judge(int n) {
	int sum = 0;
	int temp;
	ifstream f3("123.txt");
	while (!f3.eof()) {
		f3 >> temp;
		if (temp == n) {
			sum++;
			break;
		}
	}
	return sum;
}
//50527 50873