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
void PreOrder(BitTree T);
void InOrder(BitTree T);
void PostOrder(BitTree T);
void LevelOrder(BitTree T);
void Level_Queue_Order(queue<BitTree> A);
int Tree_Depth(BitTree T);
void LL_rotate(BitTree* T);
void RR_rotate(BitTree* T);
void LR_rotate(BitTree* T);
void RL_rotate(BitTree* T);
int Get_balance(BitTree T);
void Adjust_Tree(BitTree* T);
void Post_Adjust_Tree(BitTree* T);

int main() {
	int n;
	n = 100;
	BitTree T = NULL;
	//srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		//Insert_Tree(&T, rand() % n + 1);
		Insert_Tree(&T, i);
		Post_Adjust_Tree(&T);
	}

	cout << "Depth:\n";
	cout << Tree_Depth(T);
	cout << endl << endl;

	cout << "PreOrder:\n";
	PreOrder(T);
	cout << endl << endl;

	cout << "InOrder:\n";
	InOrder(T);
	cout << endl << endl;

	cout << "PostOrder:\n";
	PostOrder(T);
	cout << endl << endl;

	cout << "LevelOrder:\n";
	LevelOrder(T);
	cout << endl << endl;
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
	else if ((*T)->data < n)
		return Insert_Tree(&(*T)->rchild, n);
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

void LevelOrder(BitTree T) {
	queue<BitTree> temp;
	temp.push(T);
	Level_Queue_Order(temp);
}

void Level_Queue_Order(queue<BitTree> A) {
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
		Level_Queue_Order(temp);
}

int Tree_Depth(BitTree T) {
	int left, right;
	left = right = 0;
	if (T == NULL)
		return 0;
	left = Tree_Depth(T->lchild);
	right = Tree_Depth(T->rchild);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

void LL_rotate(BitTree* T) {
	BitTree A, B;
	A = *T;
	B = (*T)->lchild;
	A->lchild = B->rchild;
	B->rchild = A;
	*T = B;
}

void RR_rotate(BitTree* T) {
	BitTree A, B;
	A = *T;
	B = (*T)->rchild;
	A->rchild = B->lchild;
	B->lchild = A;
	*T = B;
}

void LR_rotate(BitTree* T) {
	RR_rotate(&(*T)->lchild);
	if (Get_balance(*T) == 2)
		LL_rotate(T);
}

void RL_rotate(BitTree* T) {
	LL_rotate(&(*T)->rchild);
	if (Get_balance(*T) == (-2))
		RR_rotate(T);
}

void Adjust_Tree(BitTree* T) {
	if (Get_balance(*T) == 0 || Get_balance(*T) == 1 || Get_balance(*T) == -1)
		return;
	else if (Get_balance(*T)==2) {
		if (Get_balance((*T)->lchild) >= 1)
			LL_rotate(T);
		else
			LR_rotate(T);
	}
	else if (Get_balance(*T) == -2) {
		if (Get_balance((*T)->rchild) <= -1)
			RR_rotate(T);
		else
			RL_rotate(T);
	}
}

int Get_balance(BitTree T) {
	return Tree_Depth(T->lchild) - Tree_Depth(T->rchild);
}

void Post_Adjust_Tree(BitTree* T) {
	if (*T != NULL) {
		Post_Adjust_Tree(&(*T)->lchild);
		Post_Adjust_Tree(&(*T)->rchild);
		Adjust_Tree(T);
	}
}