#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;

int Insert_Tree(BitTree* T, int n);
void LevelOrder(queue<BitTree> A);
void PostOrder(BitTree T);
void PreOrder(BitTree T);
void InOrder(BitTree T);

void wpl_PreOrder(BitTree root, int deep);
int wpl = 0;
int main() {
	BitTree T = NULL;
	int n;
	cin >> n;
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		Insert_Tree(&T, rand() % 100 + 1);
	}

	cout << "PreOrder:  ";
	PreOrder(T);
	cout << endl;

	cout << "InOrder:   ";
	InOrder(T);
	cout << endl;

	cout << "PostOrder: ";
	PostOrder(T);
	cout << endl;

	cout << "LevelOrder:\n";
	queue<BitTree> A;
	A.push(T);
	LevelOrder(A);
	cout << endl;

	wpl_PreOrder(T, 1);
	cout << wpl << endl;
}

//2014年数据结构
void wpl_PreOrder(BitTree root, int deep) {
	if (root == NULL)
		return;
	if (root->lchild == NULL && root->rchild == NULL)
		wpl += root->data * deep;
	if (root->lchild != NULL)
		wpl_PreOrder(root->lchild, deep + 1);
	if (root->rchild != NULL)
		wpl_PreOrder(root->rchild, deep + 1);
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

void PostOrder(BitTree T) {
	if (T == NULL)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	cout << T->data << " ";
}

void InOrder(BitTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
	}
}

void PreOrder(BitTree T) {
	if (T == NULL)
		return;
	cout << T->data << " ";
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

int Insert_Tree(BitTree* T, int n) {
	if (!*T) {
		*T = new BitNode;
		(*T)->data = n;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		return 1;
	}
	if ((*T)->data == n)
		return 0;
	else if ((*T)->data > n)
		return Insert_Tree(&(*T)->lchild, n);
	else if((*T)->data<n)
		return Insert_Tree(&(*T)->rchild, n);
}