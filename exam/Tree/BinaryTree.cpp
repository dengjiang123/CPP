#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
typedef struct BitNode{
	int data;
	BitNode* lc;
	BitNode* rc;

}BitNode, * BitTree;
void Create(queue<BitTree> A);
void PreOrder(BitTree T);
void PreOrder2(BitTree T);
void InOrder(BitTree T);
void InOrder2(BitTree T);
void PostOrder(BitTree T);
void LevelOrder(queue<BitTree> A);
queue<BitTree> All;
int n = 0;
int f = 15;
int main() {
	cin >> f;
	BitTree T;
	T = new BitNode;
	T->lc = T->rc = NULL;
	All.push(T);
	Create(All);
	
	LevelOrder(All);
	cout << endl << endl;
	
	PreOrder(T);
	cout << endl << endl;

	PreOrder2(T);
	cout << endl << endl;

	InOrder(T);
	cout << endl << endl;

	InOrder2(T);
	cout << endl << endl;

	PostOrder(T);
	cout << endl << endl;
	
}

void Create(queue<BitTree> A) {
	queue<BitTree> temp;
	f -= A.size();
	//cout << f << endl;
	while (!A.empty()) {
		n++;
		A.front()->data = n;
		A.front()->lc = NULL;
		A.front()->rc = NULL;
		if (f > 0) {
			A.front()->lc = new BitNode;
			temp.push(A.front()->lc);
			f--;
		}
		if (f > 0) {
			A.front()->rc = new BitNode;
			temp.push(A.front()->rc);
			f--;
		}
		A.pop();
	}
	
	f += temp.size();
	if(!temp.empty())
		Create(temp);
}

void PreOrder(BitTree T) {
	if (T == NULL)
		return;
	cout << T->data << " ";
	PreOrder(T->lc);
	PreOrder(T->rc);
}

void InOrder(BitTree T) {
	if (T == NULL)
		return;
	InOrder(T->lc);
	cout << T->data << " ";
	InOrder(T->rc);
}

void PostOrder(BitTree T) {
	if (T == NULL)
		return;
	PostOrder(T->lc);
	PostOrder(T->rc);
	cout << T->data << " ";
}

void LevelOrder(queue<BitTree> A) {
	queue<BitTree> temp;
	while (!A.empty()) {
		cout << A.front()->data << " ";
		if (A.front()->lc != NULL)
			temp.push(A.front()->lc);
		if (A.front()->rc != NULL)
			temp.push(A.front()->rc);
		A.pop();
	}
	cout << endl;
	if(temp.size())
		LevelOrder(temp);
}

void InOrder2(BitTree T) {
	stack<BitTree> temp;
	BitTree p = T;
	while (p || !temp.empty()) {
		if (p) {
			temp.push(p);
			p = p->lc;
		}
		else {
			cout << temp.top()->data << " ";
			p = temp.top()->rc;
			temp.pop();
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
			p = p->lc;
		}
		else {
			p = temp.top()->rc;
			temp.pop();
		}
	}
}

/*
void LevelOrder(BitTree T) {
	queue<BitTree> temp;
	temp.push(T);
	while (!temp.empty()) {
		if (temp.front()->lc != NULL)
			temp.push(temp.front()->lc);
		if (temp.front()->rc != NULL)
			temp.push(temp.front()->rc);
		cout << temp.front()->data << " ";
		temp.pop();
	}
}
*/