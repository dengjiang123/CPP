#include<iostream>
#include<ctime>
#include<mutex>
#include<thread>
#include<Windows.h>
#include<condition_variable>
using namespace std;
mutex mu;
void producer();
void consumer();
char new_ch();
int n = 10;
char buffer[10];
int in = 0;
int out = 0;
int countb = 0;
int main() {
	
	thread P, C;
	P = thread(producer);
	C = thread(consumer);
	P.join();
	C.join();
	return 0;
}

char new_ch() {
	srand(time(NULL));
	char ch;
	ch = rand() % 26 + 'a';
	return ch;
}

void producer() {
	char ch;
	while (1) {
		ch = new_ch();
		mu.lock();
		cout << "Produce: " << ch << "   " << countb << "   " << in << endl;
		mu.unlock();
		while (countb == n)
			Sleep(500);
		buffer[in] = ch;
		in = (in + 1) % n;
		countb++;
		Sleep(1000);
	}
}

void consumer() {
	char ch;
	while (1) {
		while (countb == 0)
			Sleep(2000);
		ch = buffer[out];
		mu.lock();
		cout << "                              Consum: " << ch << "   " << countb << "    " << out << endl;
		mu.unlock();
		Sleep(1000);
		out = (out + 1) % n;
		countb--;
	}
}