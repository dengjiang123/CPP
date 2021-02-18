#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	stack<int> x;
	for (int i = 1; i <= n; i++) {
		x.push(i);
	}
	cout << "stack:" << endl;
	while (!x.empty()) {
		cout << x.top() << endl;
		x.pop();
	}
	return 0;
}