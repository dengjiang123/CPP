#include<iostream>
using namespace std;

struct list {
	int data;
	list* next;
	list(int data1=-1 , list* next1 = nullptr) {
		data = data1;
		next = next1;
	}
};

void show(list* x);

int main() {
	int n;
	cin >> n;
	list* f = new list(3333);
	list* temp = new list();
	for (int i = 0; i < n; i++) {
		temp = new list((i + 1) * (i + 1), f);
		f = temp;
	}
	list* head = new list(0, f);
	show(head);
	return 0;
}

void show(list* x) {
	list* f = new list();
	f = x;
	while (f != nullptr) {
		cout << f->data << endl;
		f = f->next;
	}
}