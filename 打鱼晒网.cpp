#include<iostream>
#include<ctime>
int judge(int a);
int count(int a, int b, int c);
using namespace std;
int main() {
	int year, month, day;
	cin >> year >> month >> day;
	clock_t start, end;
	start = clock();

	//int year, month, day;
	//cin >> year >> month >> day;
	int  sum = count(year, month, day);
	int x = sum % 5;
	cout << sum;
	if (x > 0 && x < 4) {
		cout << "今天打鱼";
	}
	else {
		cout << "惊天晒网";
	}
	cout << endl;

	end = clock();
	cout << (end-start) <<"ms"<<endl;
	
	return 0;
}

int judge(int a) {
	if ((a / 400 == 0) || (a / 4 == 0 && a / 100 != 0)) {
		return 1;
	}
	else return 0;
}

int count(int a, int b, int c) {
	int x[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31} };
	int sum = 0;
	for (int i = 1990; i < a; i++) {
		if (judge(i)) {
			sum += 366;
		}
		else {
			sum += 365;
		}
	}
	for (int j = 0; j < b - 1; j++) {
		int t = judge(a);
		sum += x[t][j];
	}
	sum += c;
	return sum;
}