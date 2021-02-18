#include<iostream>
using namespace std;
#define MAX_Vertex 100

typedef struct node {
	int adjvex;
	node* next;
}EdgeNode;

typedef struct {
	char vertex;
	EdgeNode* edgenext;
}VertexNode;

typedef VertexNode AdjList[MAX_Vertex];

typedef struct {
	AdjList adjlist;
	int vexnum;
	int arcnum;
}AdjMaxtrix;

void Create_MG(AdjMaxtrix& G);
void Print_MG(AdjMaxtrix& G);

int main() {
	AdjMaxtrix G;
	Create_MG(G);
	Print_MG(G);
}

void Create_MG(AdjMaxtrix& G) {
	cout << "输入顶点数和边数:\n";
	cin >> G.vexnum >> G.arcnum;
	char temp;
	temp = cin.get();
	for (int i = 0; i < G.vexnum; i++) {
		temp = cin.get();
		G.adjlist[i].vertex = temp;
		G.adjlist[i].edgenext = NULL;
		temp = cin.get();
	}
	int ta, tb;
	EdgeNode* s;
	for (int i = 0; i < G.arcnum; i++) {
		cin >> ta >> tb;
		ta -= 1;
		tb -= 1;
		s = new EdgeNode;
		s->adjvex = tb + 1;
		s->next = G.adjlist[ta].edgenext;
		G.adjlist[ta].edgenext = s;
		s = new EdgeNode;
		s->adjvex = ta + 1;
		s->next = G.adjlist[tb].edgenext;
		G.adjlist[tb].edgenext = s;
	}
}

void Print_MG(AdjMaxtrix& G) {
	cout << "Vertexnum:  " << G.vexnum << endl;
	cout << "arcnum:     " << G.arcnum << endl;
	EdgeNode* temp;
	for (int i = 0; i < G.vexnum; i++) {
		cout << G.adjlist[i].vertex << " : ";
		cout << i + 1 << "-";
		temp = G.adjlist[i].edgenext;
		while (temp != NULL) {
			cout << temp->adjvex << "-";
			temp = temp->next;
		}
		cout << endl;
	}
	cout << endl;
}


/*
5 6
a
b
c
d
e
1 2
1 4
2 3
2 5
3 4
3 5
*/