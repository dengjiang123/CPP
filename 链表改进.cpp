#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

typedef struct list {
	int data;
	list* next;
}list;

list* newlist(int n);       //新建的n个链表
void show(list* start);     //输出start链表后的所有节点值
int count(list* start);      //计算链表节点数量
list* deletelist(list* start, int i);      //删除start之后的n个链表
void addlist(list* start, int n, int number);   //在链表值n后插入数字number
list* getlist(list* start, int n);   //获取start之后n个链表的链表地址
void revice(list* start, int n, int number);  //修改第n个链表值为number

int main() {
	list* start;
	int n = 100;
	start = newlist(n);
	for (int i = n; i >= 1; i--) {
		getlist(start, n - i + 1)->data = i * i;
	}
	show(start);
	return 0;
}

list* newlist(int n) {
	list* point, * start;
	start = new list;
	start->data = 1;
	point = start;
	for (int i = 1; i < n; i++) {
		list* next;
		next = new list;
		point->next = next;
		next->data = i + 1;
		point = next;
		point->next = NULL;
	}
	return start;
}

void show(list* start) {
	list* point;
	point = start;
	int sum = 0;
	for (int i = 1; i <= count(start); i++) {
		sum++;
		cout << setw(6) << point->data;
		point = point->next;
		if (sum % 20 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

int count(list* start) {
	int sum = 1;
	list* point;
	point = start;
	while (point->next != NULL) {
		sum++;
		point = point->next;
	}
	return sum;
}

list* deletelist(list* start, int i) {
	int n = count(start);
	list* point;
	list* temp;
	point = start;
	temp = point;
	if (i <= n) {
		for (int j = 1; j < i; j++) {
			temp = point;
			point = point->next;
		}
		if (i > 1 && i < n) {
			temp->next = point->next;
			delete point;
		}
		else if (i == n) {
			temp->next = NULL;
			delete point;
		}
		else if (i == 1) {
			point = point->next;
			delete start;
			start = point;
		}
	}
	return start;
}

void addlist(list* start, int n, int number) {
	list* end;
	end = new list;
	end->data = number;
	end->next = getlist(start, n + 1);
	getlist(start, n)->next = end;
}

list* getlist(list* start, int n) {
	list* answer;
	answer = start;
	for (int i = 1; i < n; i++) {
		answer = answer->next;
	}
	return answer;
}

void revice(list* start, int n, int number) {
	getlist(start, n)->data = number;
}