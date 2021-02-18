#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct node {
	int x;
	struct node* next;
};
struct node* new_node(int n);
int main() {
	int n;
	scanf("%d", &n);
	struct node* start, * p;
	start = new_node(n);
	p = start;
	for (int i = 0; i <= n; i++) {
		printf("%d ", p->x);
		p = p->next;
	}
	return 0;
}

struct node* new_node(int n){
	struct node* start,*end;
	start = (struct node*)malloc(sizeof(struct node));
	start->x = n;
	end = start;
	for (int i = 1; i <= n; i++) {
		struct node* p = (struct node*)malloc(sizeof(struct node));
		p->x = i;
		end->next = p;
		end = p;
	}
	end->next = NULL;
	return start;
}