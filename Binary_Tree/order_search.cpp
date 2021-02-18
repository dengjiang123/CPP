#include<iostream>
#include<random>
#include<ctime>
#include<queue>
#include<stack>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lchild, * rchild;
}BitNode, * BitTree;

int Insert(BitTree* T, int n);
void InOrder(BitTree T);
void InOrder2(BitTree T);
void LevelOrder(BitTree T);
void LevelOrder2(BitTree T);
void PreOrder(BitTree T);
void PreOrder2(BitTree T);
void PostOrder(BitTree T);
void PostOrder2(BitTree T);
void PostOrder3(BitTree T);
int Tree_Depth(BitTree T);
int Tree_Depth2(BitTree T);
void LevelOrderA(queue<BitTree> A);

int main() {
	BitTree T = NULL;
	int num;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		num = rand() % 100 + 1;
		//cout << num << " ";
		Insert(&T, num);
	}
	
	cout << "Level:" << endl;
	LevelOrder(T);
	cout << endl << endl;

	cout << "Level_down_to_up:" << endl;
	LevelOrder2(T);
	cout << endl << endl;

	cout << "InOrder:" << endl;
	InOrder(T);
	cout << endl << endl;

	cout << "InOrder2:" << endl;
	InOrder2(T);
	cout << endl << endl;

	cout << "PreOrder:" << endl;
	PreOrder(T);
	cout << endl << endl;

	cout << "PreOrder2:" << endl;
	PreOrder2(T);
	cout << endl << endl;

	cout << "PostOrder:" << endl;
	PostOrder(T);
	cout << endl << endl;

	cout << "PostOrder2:" << endl;
	PostOrder2(T);
	cout << endl << endl;

	cout << "PostOrder3:" << endl;
	PostOrder3(T);
	cout << endl << endl;

	cout << "Tree_Depth:" << endl;
	cout << Tree_Depth(T);
	cout << endl << endl;

	cout << "LevelA:" << endl;
	queue<BitTree> temp;
	temp.push(T);
	LevelOrderA(temp);
	cout << endl << endl;
}

int Tree_Depth2(BitTree T) {
	
}

void LevelOrderA(queue<BitTree> A) {
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
		LevelOrderA(temp);
}

int Tree_Depth(BitTree T) {
	int ldep, rdep;
	ldep = rdep = 0;
	if (!T)
		return 0;
	ldep = Tree_Depth(T->lchild);
	rdep = Tree_Depth(T->rchild);
	if (ldep > rdep)
		return ldep + 1;
	else
		return rdep + 1;
}

void PostOrder3(BitTree T) {
	stack<BitTree> temp;
	BitTree p, r;
	p = T;
	r = NULL;
	while (p || !temp.empty()) {
		if (p) {
			temp.push(p);
			p = p->lchild;
		}
		else {
			p = temp.top();
			if (p->rchild != NULL && p->rchild != r) {
				p = p->rchild;
				temp.push(p);
				p = p->lchild;
			}
			else {
				cout << temp.top()->data << " ";
				r = temp.top();
				temp.pop();
				p = NULL;
			}
		}
	}
}

void PostOrder2(BitTree T) {
	stack<BitTree> temp;
	BitTree p, r;
	p = T;
	r = NULL;
	while (p || !temp.empty()) {
		if (p) {
			temp.push(p);
			p = p->lchild;
		}
		else {
			p = temp.top();
			if (p->rchild != NULL && p->rchild != r) {
				p = p->rchild;
				temp.push(p);
				p = p->lchild;
			}
			else {
			/*	cout << temp.top()->data << " ";
				r = temp.top();
				temp.pop();
				p = NULL;      */
				p = temp.top();
				temp.pop();
				cout << p->data << " ";
				r = p;
				p = NULL;    
			}
		}
	}
}

void PreOrder2(BitTree T) {
	stack<BitTree> temp;
	BitTree p = T;
	while (p || !temp.empty()) {
		if (p) {
			cout << p->data << " ";
			temp.push(p);
			p = p->lchild;
		}
		else {
			p = temp.top()->rchild;
			temp.pop();
		}
	}
}

void InOrder2(BitTree T) {
	stack<BitTree> temp;
	BitTree p = T;
	while (p || !temp.empty()) {
		if (p) {
			temp.push(p);
			p = p->lchild;
		}
		else {
			cout << temp.top()->data << " ";
			p = temp.top()->rchild;
			temp.pop();
		}
	}
}

void PostOrder(BitTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
	}
}

void PreOrder(BitTree T) {
	if (T != NULL) {
		cout << T->data << ",";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BitTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		cout << T->data << ",";
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
}

void LevelOrder2(BitTree T) {
	stack<BitTree> temp;
	queue<BitTree> Q;
	Q.push(T);
	while (Q.empty() == 0) {
		temp.push(Q.front());
		if (Q.front()->lchild != NULL)
			Q.push(Q.front()->lchild);
		if (Q.front()->rchild != NULL)
			Q.push(Q.front()->rchild);
		Q.pop();
	}
	while (!temp.empty()) {
		cout << temp.top()->data << " ";
		temp.pop();
	}
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