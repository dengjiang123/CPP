#include<iostream>
using namespace std;
int main() {
	int x[4] = {};
	x[1] = 1;
	int t;
	cout << x[1] << " " << x[2] << " " << x[3] << " " << x[1] + x[2] + x[3] << endl;
	for (int i = 2; i <= 30; i++) {
		t = x[3] + x[2];
		x[3] += x[2];
		x[2] = x[1];
		x[1] = t;
		cout << x[1] << " " << x[2] << " " << x[3] << " " << x[1] + x[2] + x[3] << endl;
	}
	cout << x[1] + x[2] + x[3];
	return 0;
}