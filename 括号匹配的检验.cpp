#include<iostream>
#include<stack>
using namespace std;
int judge(char ch1, char ch2);
int main() {
	stack<char> x;
	char ch;
	ch = getchar();
	x.push(ch);
	ch = getchar();
	while (ch != '\n') {
		if (judge(x.top(), ch)) {
			cout << x.top() << " " << ch << endl;
			x.pop();
		}
		else
			x.push(ch);
		ch = getchar();
	}
	return 0;
}

int judge(char ch1, char ch2) {
	if (ch1 == '(' && ch2 == ')') return 1;
	else if (ch1 == '{' && ch2 == '}') return 1;
	else if (ch1 == '[' && ch2 == ']') return 1;
	else return 0;
}