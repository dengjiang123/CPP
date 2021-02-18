#include<iostream>
#include<stack>
#include<cmath>
void fac();
using namespace std;
int main() {
	fac();
	return 0;
}

void fac() {
	stack<int> mystack;
	char c;
	int t=0;
	double sum = 0;
	cin >> c;
	do {
		mystack.push(c - '0');
		t++;
		cin >> c;
	} while (c != '#');
	for (int i = 1; i <= t; i++) {
		sum = sum + mystack.top() * int(pow(2, i-1));
		mystack.pop();
	}
	cout << sum;
}