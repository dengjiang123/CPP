#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<fstream>
using namespace std;
typedef struct BitNode {
	//char ch;
	int data;
	vector<bool> code;
	BitNode* lchild;
	BitNode* rchild;
}BitNode, * BitTree;

void Sort_Tree(vector<BitTree>* Tree);
void Show_Tree(const vector<BitTree>* Tree);
BitTree Create_Huff_Tree(BitTree A, BitTree B);
void LevelOrder(BitTree T);
void Level_Queue_Order(queue<BitTree> A);
void WPL_Tree(BitTree T, int deep);
void Code_Tree(BitTree T);
void Code_Order(BitTree T);
int wpl = 0;
int all = 0;
int yuan;

int main() {
	vector<int> num = { 10,35,40,50,60,200 };
	//vector<int> number = { 2,3,6,9,13 };
	vector<BitTree> Tree;
	for (int i = 0; i < num.size(); i++) {
		BitTree T;
		T = new BitNode;
		T->lchild = T->rchild = NULL;
		T->data = num[i];
		
		Tree.push_back(T);
	}

	while (Tree.size() > 1) {
		Sort_Tree(&Tree);
		Show_Tree(&Tree);
		Tree.push_back(Create_Huff_Tree(Tree[0], Tree[1]));
		Tree.erase(Tree.begin(), Tree.begin() + 2);
	}

	BitTree start = Tree[0];
	LevelOrder(start);
	WPL_Tree(start, 0);
	cout << "WPL:   " << wpl << endl << endl;
	Code_Tree(start);
	Code_Order(start);
	cout << endl << all << " bit" << endl;
	cout << yuan << "  bit" << endl;
	cout << 1.0 * all / yuan << endl;
}

void Code_Order(BitTree T) {
	if (T != NULL) {
		Code_Order(T->lchild);
		if (T->lchild == NULL && T->rchild == NULL) {
			cout << " " << T->data << " : ";
			for (int i = 0; i < T->code.size(); i++) {
				cout << T->code[i];
			}
			all += (T->code.size() * T->data);
			yuan += (T->data) * 8;
			cout << endl;
		}
		Code_Order(T->rchild);
	}
}

void Sort_Tree(vector<BitTree>* Tree) {
	BitTree temp = NULL;
	int n = (*Tree).size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((*Tree)[i]->data > (*Tree)[j]->data) {
				temp = (*Tree)[i];
				(*Tree)[i] = (*Tree)[j];
				(*Tree)[j] = temp;
			}
		}
	}
}

void Show_Tree(const vector<BitTree>* Tree) {
	int n = (*Tree).size();
	for (int i = 0; i < n; i++) {
		cout << (*Tree)[i]->data << " ";
	}
	cout << endl << endl;
}

BitTree Create_Huff_Tree(BitTree A, BitTree B) {
	BitTree start = new BitNode;
	start->lchild = A;
	start->rchild = B;
	start->data = A->data + B->data;
	return start;
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

void WPL_Tree(BitTree T, int deep) {
	if (T == NULL)
		return;
	if (T->lchild == NULL && T->rchild == NULL)
		wpl += T->data * deep;
	if (T->lchild != NULL)
		WPL_Tree(T->lchild, deep + 1);
	if (T->rchild != NULL)
		WPL_Tree(T->rchild, deep + 1);
}

void Code_Tree(BitTree T) {
	if (T != NULL) {
		if (T->lchild != NULL) {
			for (int i = 0; i < (T->code).size(); i++) {
				((T->lchild)->code).push_back((T->code)[i]);
			}
			((T->lchild)->code).push_back(0);
			Code_Tree(T->lchild);
		}
		if (T->rchild != NULL) {
			for (int i = 0; i < (T->code).size(); i++) {
				((T->rchild)->code).push_back((T->code)[i]);
			}
			((T->rchild)->code).push_back(1);
			Code_Tree(T->rchild);
		}
	}
}