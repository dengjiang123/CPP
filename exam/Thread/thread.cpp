#include<iostream>
#include<thread>
#include<ctime>
#include<vector>
#include<mutex>
using namespace std;
int fac(int n);
void run(int n);
mutex mu;
vector<int> answer;

int main() {
	vector<thread> th;
	clock_t start, end;
	int n = 100;
	int test = 40;
	start = clock();

	for (int i = 1; i <= n; i++) {
		th.push_back(thread(run, test));
	}

	for (int i = 0; i < n; i++)
		th[i].join();

	end = clock();
	for (int i = 0; i < answer.size(); i++) {
		cout << i << " " << answer[i] << endl;
	}
	cout << end - start << " ms";
}

int fac(int n) {
	if (n <= 1)
		return n;
	else
		return fac(n - 1) + fac(n - 2);
}

void run(int n) {
	///mu.lock();
	//unique_lock<mutex> lock(mu);
	answer.push_back(fac(n));
	///mu.unlock();
}