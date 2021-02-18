#include<iostream>
#include<vector>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;

BitTree PreInCreate(int* A, int* B, int l1, int h1, int l2, int h2);
void PostOrder(BitTree T);

int main() {
	int* Pre = new int[] {42, 35, 1, 25, 6, 28, 37, 68, 59, 46, 43, 63, 62, 65, 70, 79, 82, 92, 96};
	int* In = new int[] {1, 6, 25, 28, 35, 37, 42, 43, 46, 59, 62, 63, 65, 68, 70, 79, 82, 92, 96};
	            //Post 5,9,7,13,19,15,12
	BitTree T;

	T = PreInCreate(Pre, In, 0, 18, 0, 18);
	PostOrder(T);
}

BitTree PreInCreate(int* A, int* B, int l1, int h1, int l2, int h2) {
	BitTree root;
	root = new BitNode;
	root->data = A[l1];
	int i;
	for (i = l2; B[i] != root->data; i++);
	int llen, rlen;
	llen = i - l2;
	rlen = h2 - i;
	if (llen)
		root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	if (rlen)
		root->rchild = PreInCreate(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}

void PostOrder(BitTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}