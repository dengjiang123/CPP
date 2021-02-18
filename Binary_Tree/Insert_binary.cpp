#include<iostream>
#include<random>
#include<ctime>
#include<queue>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild, * rchild;
}BitNode, * BitTree;

int Insert(BitTree* T, int n);
void InOrder(BitTree T);
void LevelOrder(BitTree T);
void PreOrder(BitTree S);

int main() {
	BitTree T;
	int num;
	
	for (int i = 1; i <= 10; i++) {
		num = rand() % 100 + 1;
		cout << num << " ";
		Insert(&T, num);
	}
	cout << endl << endl;
	LevelOrder(T);
	InOrder(T);
	cout << endl << endl;
	PreOrder(T);
}

void PreOrder(BitTree S) {
	if (S != NULL) {
		cout << S->data << " ";
		PreOrder(S->lchild);
		PreOrder(S->rchild);
		cout << endl;
	}
}

void InOrder(BitTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
	}
}

void LevelOrder(BitTree T) {
	queue<BitTree> Q;
	Q.push(T);
	while (Q.empty() == 0) {
		cout << Q.front()->data << " ";
		if (Q.front()->lchild != NULL)
			Q.push(Q.front()->lchild);
		if (Q.front()->rchild != NULL)
			Q.push(Q.front()->rchild);
		Q.pop();
	}
	cout << endl << endl;
}

int Insert(BitTree* T, int n) {
	if (*T == NULL) {
		*T = new BitNode;
		(*T)->data = n;
		(*T)->lchild = (*T)->rchild = NULL;
		return 1;
	}
	else if ((*T)->data == n)
		return 0;
	else if ((*T)->data > n)
		return Insert(&(*T)->lchild, n);
	else
		return Insert(&(*T)->rchild, n);
}