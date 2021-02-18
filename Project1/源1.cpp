#include<iostream>
using namespace std;
typedef struct node {
	int x;
	node* next;
}node;
node* newnode(int n);
node* get_node(node* start, int n);
int count_node(node* start);
void delete_node(node* start, int n);
void show_node(node* start);
void insert_node(node* start, int n, int number);
void adjust_node(node* start, int n, int number);
void sort_node(node* start);
node* merge_node(node* st1, node* st2);
void merge_add_node(node* st1, node* st2);
int main() {
	int m, n;
	node* start1, * start2, * ans;

	cin >> m;
	start1 = newnode(m);
	
	cin >> n;
	start2 = newnode(n);

	show_node(start1);
	show_node(start2);

	sort_node(start1);
	sort_node(start2);

	show_node(start1);
	show_node(start2);

	//ans = merge_node(start1, start2);
	//show_node(ans);

	merge_add_node(start1, start2);
	show_node(start1);
	show_node(start2);
	return 0;
}

node* newnode(int n) {
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
	end->next = NULL;
	return start;
}

node* get_node(node* start, int n) {
	node* ans;
	ans = start;
	for (int i = 1; i <= n; i++) {
		ans = ans->next;
	}
	return ans;
}

int count_node(node* start) {
	int n = 0;
	node* p;
	p = start;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void show_node(node* start) {
	node* p;
	p = start;
	cout << start->x << ": ";
	do {
		p = p->next;
		cout << p->x << " ";
	} while (p->next != NULL);
	cout << endl << endl;
}

void delete_node(node* start, int n) {
	node* p, * next;
	p = start;
	start->x -= 1;
	for (int i = 1; i < n; i++) {
		p = p->next;
	}
	next = p->next;
	p->next = next->next;
	delete next;
}

void insert_node(node* start, int n, int number) {
	node* p = get_node(start, n);
	node* ne = new node;
	ne->x = number;
	ne->next = p->next;
	p->next = ne;
	start->x += 1;
}

void adjust_node(node* start, int n, int number) {
	node* p = get_node(start, n);
	p->x = number;
}

void sort_node(node* start) {
	node* p;
	p = start->next;
	int n = start->x;
	int* x = new int[n];
	for (int i = 0; i < n; i++) {
		x[i] = p->x;
		if((p->next))
			p = p->next;
	}
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] > x[j]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	p = start->next;
	for (int i = 0; i < n; i++) {
		p->x = x[i];
		if ((p->next))
			p = p->next;
	}
}

node* merge_node(node* st1, node* st2) {
	node* p1, * p2, * p3, * end, * start;
	int n;
	n = st1->x + st2->x;
	p1 = st1->next;
	p2 = st2->next;

	start = new node;
	end = start;
	start->x = n;
	for (int i = 0; i < n; i++) {
		p3 = new node;
		end->next = p3;
		end = p3;
		if (p1 && p1->x < p2->x) {
			end->x = p1->x;
			p1 = p1->next;
		}
		else if(p2){
			end->x = p2->x;
			p2 = p2->next;
		}
	}
	end->next = NULL;
	return start;
}

void merge_add_node(node* st1, node* st2) {
	node* p1, * p2, * p3;
	p1 = st1->next;
	p2 = st2->next;
	p3 = st1;
	st1->x += st2->x;
	while (p1 && p2) {
		if (p1->x < p2->x) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
}