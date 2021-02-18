#include<iostream>
#include<queue>
using namespace std;
typedef char VertexType;
typedef int EdgeType;

typedef struct {
	int vexnum;
	int edgenum;
	VertexType* vex;
	EdgeType** edges;
}MGraph;

bool* visited;

void Create_MG(MGraph& G);
void Print_MG(MGraph& G);

void BFSTraverse(MGraph& G);
void BFS(MGraph& G, int v);
void DFSTraverse(MGraph& G);
void DFS(MGraph& G, int v);

int FirstNeighbor(MGraph& G, int v);
int NextNeighbor(MGraph& G, int v, int w);
int Exist_Path_DFS(MGraph& G, int i, int j);

queue<VertexType> Q;

int main() {
	MGraph G;
	Create_MG(G);
	Print_MG(G);
	cout << endl;

	cout << "BFSTraverse: ";
	BFSTraverse(G);
	cout << endl << endl;
	cout << "DFSTraverse: ";
	DFSTraverse(G);
	return 0;
}

void DFSTraverse(MGraph& G) {
	//visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;
	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			DFS(G, i);
}

void DFS(MGraph& G, int v) {
	cout << v + 1 << " ";
	visited[v] = true;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		if (!visited[w])
			DFS(G, w);
}

int FirstNeighbor(MGraph& G, int v) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.edges[v][i])
			return i;
	return -1;
}

int NextNeighbor(MGraph& G, int v, int w) {
	for (int i = w + 1; i < G.vexnum; i++)
		if (G.edges[v][i])
			return i;
	return -1;
}

void BFSTraverse(MGraph& G) {
	visited = new bool[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;
	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			BFS(G, i);
}

void BFS(MGraph& G, int v) {
	cout << v + 1 << " ";
	visited[v] = true;
	Q.push(v);
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
			if (!visited[w]) {
				cout << w + 1 << " ";
				visited[w] = true;
				Q.push(w);
			}
	}
}

void Create_MG(MGraph& G) {
	cout << "输入顶点数，边数:\n";
	cin >> G.vexnum >> G.edgenum;
	cout << "输入边:\n";
	G.edges = new EdgeType * [G.vexnum];
	for (int i = 0; i < G.vexnum; i++) {
		G.edges[i] = new EdgeType[G.vexnum];
		for (int j = 0; j < G.vexnum; j++)
			G.edges[i][j] = 0;
	}
	int ta, tb;
	for (int i = 0; i < G.edgenum; i++) {
		cin >> ta >> tb;
		G.edges[ta][tb] = G.edges[tb][ta] = 1;
	}
}

void Print_MG(MGraph& G) {
	cout << "Vertexnum:  " << G.vexnum << endl;
	cout << "Edgenum:    " << G.edgenum << endl;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.edges[i][j] << " ";
		}
		cout << endl;
	}
}

// 5 6 0 1 0 3 1 2 1 4 2 3 2 4 