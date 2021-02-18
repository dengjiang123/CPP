#include<iostream>
using namespace std;
typedef struct node {
	int x;
	node* prior;
	node* next;
};
node* new_node(int n);
int main() {
	node* start, * p;
	int n;
	cin >> n;
	start = new_node(n);

	p = start;
	for (int i = 0; i <= n; i++) {
		cout << p->x << " ";
		p = p->next;
	}
	cout << endl;
	p = start;
	for (int i = 0; i <= n; i++) {
		cout << p->x << " ";
		p = p->prior;
	}
	return 0;
}

node* new_node(int n) {
	node* start, * end, * p;
	start = new node;
	start->x = n;
	end = start;
	for (int i = 1; i <= n; i++) {
		p = new node;
		cin >> p->x;
		end->next = p;
		end = p;
	}
	end->next = start;
	p = start;
	for (int i = 0; i <= n; i++) {
		p->prior = end;
		end = end->next;
		p = p->next;
	}
	return start;
}