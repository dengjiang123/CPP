#include<iostream>
#include<queue>
using namespace std;
typedef char VertexType;
typedef int EdgeType;

#define INF 100000

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

queue<VertexType> Q;

int main() {
	MGraph G;
	Create_MG(G);
	Print_MG(G);
	
	cout << endl;
	BFSTraverse(G);
	cout << endl;
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
		for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
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
	int ta, tb, value;
	for (int i = 0; i < G.edgenum; i++) {
		cin >> ta >> tb >> value;
		G.edges[ta-1][tb-1] = value;
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

/*
5 10
1 2 10
1 5 5
2 3 1
2 5 2
3 4 4
4 1 7
4 3 6
5 2 3
5 3 9
5 4 2
*/