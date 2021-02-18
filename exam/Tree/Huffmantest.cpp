#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;

void show(const vector<int>& P);
void Create_Huff_Tree(BitTree* T, int n);
void LevelOrder(BitTree T);
void Level_Queue_Order(queue<BitTree> A);
//void Post_Order(BitTree T);

int main() {
	int n;
	n = 10;
	vector<int> P = { 45,12,13,5,9,16 };
	show(P);
	sort(P.begin(), P.end());
	show(P);

	BitTree T = NULL;
	for (vector<int>::iterator iter = P.begin(); iter != P.end(); iter++) {
		Create_Huff_Tree(&T, *iter);
	}

	LevelOrder(T);
}

void show(const vector<int>& P) {
	int n = P.size();
	for (int i = 0; i < n; i++)
		cout << P[i] << " ";
	cout << endl << endl;
}

void Create_Huff_Tree(BitTree* T, int n) {
	BitTree LL = new BitNode;
	LL->lchild = LL->rchild = NULL;
	LL->data = n;
	if (*T == NULL) {
		*T = new BitNode;
		(*T)->data = n;
		(*T)->lchild = LL;
		(*T)->rchild = NULL;
		return;
	}
	else if ((*T)->rchild == NULL) {
		(*T)->rchild = LL;
		(*T)->data += n;
		return;
	}
	else if (n >= (*T)->data) {
		BitTree N = new BitNode;
		N->lchild = LL;
		N->rchild = (*T);
		N->data = N->lchild->data + N->rchild->data;
		(*T) = N;
		return;
	}
	else {

	}
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