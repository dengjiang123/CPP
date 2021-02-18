#include<iostream>
using namespace std;
int main() {
	int sum1, sum2,t;
	int a, b, c, d;
	for ( a = 0; a <= 9; a++) {
		for ( b = 0; b <= 9; b++) {
			for ( c = 0; c <= 9; c++) {
				for ( d = 0; d <= 9; d++) {
					sum1 = a * 1000 + b * 100 + c * 10 + d;
					sum2 = d * 1000 + c * 100 + b * 10 + a;
					if (sum1 != 0&&sum2%sum1==0) {
						t = sum2 / sum1;
						if (t != a && t != b && t != c && t != d&&t!=1&&t<=9) {
							cout << a << " " << b << " " << c << " " << d << " " << t << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}