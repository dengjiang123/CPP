




/*
#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<malloc.h>
#include <string.h>
#include <stack>
#define Maxsize 30
#define INFINITY 99999
using namespace std;

int visited[100];

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct Vnode
{
    int data;
    ArcNode* firstarc;
}VNode;

typedef VNode AdjLis[100];

typedef struct adjlist
{
    char name[10];
    int indegree;
    ArcNode* firstarc;
}adjlist;

typedef struct
{
    int n, e;
    int vexnum, arcnum;
    adjlist ver[Maxsize];
}ALGraph;

void FindInDegree(ALGraph& G)
{
    int indeg, i, j;
    ArcNode* p;
    for (i = 0; i < G.vexnum; i++)
    {
        indeg = 0;
        for (j = 0; j < G.vexnum; j++)
        {
            if (G.ver[j].firstarc != NULL)
            {
                p = G.ver[j].firstarc;
                while (p)
                {
                    if (p->adjvex == i)
                        indeg++;
                    p = p->nextarc;
                }//while
            }//if
        }//for
        G.ver[i].indegree = indeg;
    }//for
}

void TopologicalSort(ALGraph& G)
{
    int i, j, e, count;
    stack<int> s;
    ArcNode* p;
    FindInDegree(G);
    for (i = 0; i < G.vexnum; i++)
        if (!G.ver[i].indegree)
            s.push(i);
    count = 0;
    while (!s.empty())
    {
        e = s.top();
        count++;
        s.pop();
        for (p = G.ver[e].firstarc; p; p = p->nextarc)
        {
            if (!(--G.ver[p->adjvex].indegree))
                s.push(p->adjvex);
        }//for
    }//while
    if (count < G.vexnum)
    {
        cout << "该有向图有回路\n";
        return;
    }//if
    else
    {
        cout << "该有向图无回路\n";
        return;
    }
}

int Locatecity(ALGraph G, char v[])
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (!strcmp(G.ver[i].name, v))
            break;
    return i;
}

void DFS(ALGraph& G, int v)//深度优先遍历
{
    ArcNode* p;
    visited[v] = 1;
    printf("%3d", v);
    p = G.ver[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)
        {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

void BFS(ALGraph& G, int v) //广度优先遍历
{
    ArcNode* p;
    int queue[100], front = 0, rear = 0;
    int visited[100];
    int w, i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    printf("%3d", v);
    visited[v] = 1;
    rear = (rear + 1) % 100;
    queue[rear] = v;
    while (front != rear)
    {
        front = (front + 1) % 100;
        w = queue[front];
        p = G.ver[w].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                printf("%3d", p->adjvex);
                visited[p->adjvex] = 1;
                rear = (rear + 1) % 100;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    cout << endl;
}

void createGraph()
{
    ALGraph G;
    cout << "请输入图的顶点个数:";
    cin >> G.vexnum;
    cout << "请输入边数:";
    cin >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "第" << i + 1 << "个顶点的名称:";
        cin >> G.ver[i].name;
        G.ver[i].indegree = 0;
        G.ver[i].firstarc = NULL;
    }
    int n, m;
    char v1[10], v2[10];
    for (int j = 0; j < G.arcnum; j++)
    {
        cout << "请输入第" << j + 1 << "条边的起始位置与终止位置:";
        cin >> v1 >> v2;
        n = Locatecity(G, v1); m = Locatecity(G, v2);
        ArcNode* p, * q, * t;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = m;
        p->nextarc = NULL;
        if (G.ver[n].firstarc == NULL)
            G.ver[n].firstarc = p;
        else
        {
            q = G.ver[n].firstarc;
            while (q->nextarc)
                q = q->nextarc;
            q->nextarc = p;
        }
    }
    cout << "深度遍历排序：";
    DFS(G, 0);
    cout << endl << "广度遍历排序：";
    BFS(G, 0);
    TopologicalSort(G);
}



int main()
{
    createGraph();
    return 0;
}
*/





/*
#include<iostream>
using namespace std;
int main() {
	int n = 12;
	int* a, * b;
	cout << &a << endl;
	cout << &b << endl;
	a = b = &n;
	cout << &n << endl;
	cout << a << endl;
	cout << b << endl;
	cout << *a << " " << *b << " " << n << endl;
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

void f(int& n);
void a(int* n);
int main() {
	int t = 12;
	cout << t << " " << &t << endl;
	f(t);
	cout << t << " " << &t << endl;
	a(&t);
	cout << t << " " << &t << endl;
	int* p = &t;
	cout << &t << endl;
	cout << p << endl;
	cout << &p << endl;
}

void f(int& n) {
	n = 16;
	cout << n << " " << &n << endl << endl;
}

void a(int* n) {
	*n = 20;
	cout << *n << " " << n << endl << endl;
}
*/