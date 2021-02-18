#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
void read(string str);
int judge(int n);
ofstream f1("##answer##.txt");
int main() {
	clock_t start, end;
	start = clock();
	fstream file("12.txt", ios::out);
	file.close();
	system("dir /a /b *.txt >> 12.txt");
	ifstream f("12.txt");

	string str;
	while (!f.eof()) {
		getline(f, str);
		if (str == "12.txt" || str == "##answer##.txt" || str=="123.txt" || str.length()<4);
		else {
			read(str);
		}
	}
	end = clock();
	cout << end - start << "ms" << endl;
	system("pause");
	return 0;
}

void read(string str) {
	ifstream f(str);
	string temp;
	int n;
	while (!f.eof()) {
		f >> n;
		getline(f, temp);
		if (judge(n)) {
			f1 << n << temp << endl;
		}
	}
}

int judge(int n) {
	ifstream f("123.txt");
	int sum = 0;
	int m;
	while (!f.eof()) {
		f >> m;
		if (n == m) {
			sum++;
			break;
		}
	}
	return sum;
}
