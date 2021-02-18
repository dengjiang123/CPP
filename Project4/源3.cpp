#include<iostream>
#include<thread>
#include<Windows.h>
#include<ctime>
#include<vector>
#include<stdio.h>
#include<mutex>

using namespace std;
mutex mu;
int fac(int n);
void run(int n);

int main() {
	int n;
	n = 10;
	clock_t start, end;
	start = clock();
	//vector<thread> mp;
	for (int i = 1; i <= n; i++) {
		
	}
	
	end = clock();
	cout << end - start << endl;

}

void run(int n) {
	//Sleep(100);
	//printf("%d: %d\n", n, fac(40));
	//mu.lock();
	//unique_lock<mutex> lock(mu);
	cout << n << ": " << fac(45) << endl;
	/*cout << n << ": ";
	for (int i = 1; i <= 10; i++) {
		cout << fac(30 + i) << " ";
	}
	cout << endl;*/
	//mu.unlock();
}

int fac(int n) {
	if (n <= 1)
		return n;
	else
		return fac(n - 1) + fac(n - 2);
}