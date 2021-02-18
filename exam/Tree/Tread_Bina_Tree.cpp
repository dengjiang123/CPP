#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
typedef struct BitNode {
	int data;
	BitNode* lc;
	BitNode* rc;
	int ltag = 0;
	int rtag = 0;

}BitNode, * BitTree;
void Create(queue<BitTree> A);
//void InThread(BitTree p, BitTree pre);
//void CreateInThread(BitTree T);
BitTree GetPreOrder(BitTree T);
void InThread(BitTree T);
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

	//CreateInThread(T);
	BitTree p = GetPreOrder(T);
	
}



BitTree GetPreOrder(BitTree T) {
	BitTree start, p;
	p = T;
	while (p->lc)
		p = p->lc;
	start = p;
	start->ltag = 1;
	return start;
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
	if (!temp.empty())
		Create(temp);
}

/*
* 
* ½Ì²Ä´úÂë
void CreateInThread(BitTree T) {
	BitTree pre = NULL;
	if (T != NULL) {
		InThread(T, pre);
		pre->rc = NULL;
		pre->rtag = 1;
	}
}

void InThread(BitTree p, BitTree pre) {
	if (p != NULL) {
		InThread(p->lc, pre);
		if (p->lc == NULL) {
			p->lc = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->lc == NULL) {
			pre->rc = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rc, pre);
	}
}
*/