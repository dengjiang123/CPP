#include<iostream>
#include<random>
#include<ctime>
#include<Windows.h>
#include<thread>
using namespace std;
void producer();
void consumer();
int chose();
int n = 20;
int in = 0, out = 0, number = 0;
int buffer[20];
int main() {
	srand(unsigned(time(NULL)));
	thread a(producer);
	thread b(consumer);
	a.join();
	b.join();
	return 0;
}

void producer() {
	int f = 0;
	while (1) {
		Sleep(1000);
		f = chose();
		cout << "f: " << f << endl;
		if (f) {
			while (number == n) {
				cout << "";
			}
			buffer[in] = 333333;
			in = (in + 1) % n;
			number++;
			cout << "producer: " << number << endl;
		}
	}
}
void consumer() {
	int f = 0;
	while (1) {
		Sleep(1000);
		f = chose();
		cout << "f: " << f << endl;
		if (f) {
			while (number == 0) {
				cout << "";
			}
			int next;
			next = buffer[out];
			out = (out + 1) % n;
			number--;
			cout << "consumer:" << number << endl;
			cout << "End:" << next << endl;
		}
	}
}

int chose() {
	Sleep(100);
	int n = rand() % 2;
	return n;
}