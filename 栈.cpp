#include<iostream>
#include<stack>
#include<string>
using namespace std;
int left(int n, int m);
char* left(const char* str, int m);
int main() {
	int n;
	cin >> n;
	char str[30];
	cin.clear();
	cin >> str;
	char* p;
	for (int i = 1;i <= 10;i++) {
		int t = left(n, i);
		p = left(str, i);
		cout << t << " " << p << endl;
		delete[]p;
	}
	system("pause");
	return 0;
}

int left(int n, int m) {
	int t = n;
	stack<int> x;
	do {
		x.push(t % 10);
		t /= 10;
	} while (t != 0);
	int s = 0;
	int a = x.size();
	for (int i = 1;i <= m&&i<=a;i++) {
		s = s * 10 + x.top();
		x.pop();
	}
	return s;
}

char* left(const char* str, int m) {
	if (m < 0) {
		m = 0;
	}
	char* p = new char[m+1];
	int i;
	for ( i = 0;i < m && str[i];i++) {
		p[i] = str[i];
	}
	p[i] = '\0';
	return p;
}