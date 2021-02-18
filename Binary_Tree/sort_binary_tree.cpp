#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<queue>
#include<stdio.h>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;
int Insert_Tree(BitTree* T, int n);
void LevelOrder(queue<BitTree> A);
queue<BitTree> All;
int main() {
	BitTree T;
	srand(time(NULL));
	int n;
	//cin >> n;
	n = 1000;
	int temp;
	for (int i = 1; i <= n; i++) {
		temp = rand() % 10000 + 1;
		Insert_Tree(&T, temp);
	}

	All.push(T);
	LevelOrder(All);
	return 0;
}

int Insert_Tree(BitTree* T, int n) {
	if (!*T) {
		*T = new BitNode;
		(*T)->data = n;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		return 1;
	}
	else if ((*T)->data == n)
		return 0;
	else if ((*T)->data > n)
		return Insert_Tree(&(*T)->lchild, n);
	else
		return Insert_Tree(&(*T)->rchild, n);
}

void LevelOrder(queue<BitTree> A) {
	queue<BitTree> temp;
	while (!A.empty()) {
		cout << A.front()->data << " ";
		if (A.front()->lchild != NULL)
			temp.push(A.front()->lchild);
		if (A.front()->rchild != NULL)
			temp.push(A.front()->rchild);
		A.pop();
	}
	cout << endl;
	if (temp.size())
		LevelOrder(temp);
}