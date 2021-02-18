#include<iostream>
#include<queue>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;

void In_Tree(BitTree T, int n);
void LevelOrder(queue<BitTree> A);
void PreOrder(BitTree T);
queue<BitTree> All;
int main() {
	BitTree T = NULL;
	T = new BitNode;
	T->data = 5;
	T->lchild = NULL;
	T->rchild = NULL;
	int n;
	n = 10;
	for (int i = 1; i <= n; i++)
		In_Tree(T, i);

	//PreOrder(T);
	//cout << endl << endl;

	//All.push(T);
	//LevelOrder(All);
	
}

void PreOrder(BitTree T) {
	if (T == NULL)
		return;
	cout << T->data << " ";
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

void In_Tree(BitTree T, int n) {
	BitTree p;
	p = new BitNode;
	p->data = n;
	p->lchild = NULL;
	p->rchild = NULL;
	BitTree temp;
	temp = T;
	while (temp) {
		if (n < temp->data)
			temp = temp->lchild;
		else if (n > temp->data)
			temp = temp->rchild;
		
	}
	temp = p;
	//cout << p->data << " ";
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
	if (temp.size())
		LevelOrder(temp);
}