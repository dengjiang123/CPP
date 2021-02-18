#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define  MaxVertices 100
typedef struct node {   //边表 
    int adjvex;
    node* next;
}EdgeNode;

typedef struct {     //顶点表  
    char vertex;
    EdgeNode* edgenext;
}VertexNode;

typedef VertexNode AdjList[MaxVertices];

typedef struct {
    AdjList adjlist;
    int n, e;
}AdjMatrix;

void CreateGraph(AdjMatrix* G)
{
    int i, j, k, w, v;
    EdgeNode* s;
    printf("输入顶点数和边数（中间以空格分开）：");
    scanf("%d%d", &G->n, &G->e);

    printf("建立顶点表\n");
    for (i = 0; i < G->n; i++)
    {
        //fflush(stdin);  
        //如果 stream 指向输入流（如 stdin），那么 fflush 函数的行为是不确定的。
        //故而使用 fflush(stdin) 是不正确的。
        getchar();
        printf("请输入第%d个顶点的信息:", i + 1);
        G->adjlist[i].vertex = getchar();
        G->adjlist[i].edgenext = NULL;
    }
    //前插法 
    printf("建立边表\n");
    for (k = 0; k < G->e; k++)
    {
        printf("输入有连接的顶点序号：");
        scanf("%d%d", &i, &j);
        i -= 1; j -= 1;//①
        //对于直接相连的进行编入(即对输入“0 1”时，在0对应的边表中编入1) 
        s = (EdgeNode*)malloc(sizeof(EdgeNode));
        s->adjvex = j;//边表赋值 
        s->next = G->adjlist[i].edgenext;
        G->adjlist[i].edgenext = s;
        //对于间接相连的进行编入(即对输入“0 1”时，在1对应的边表中编入0)
        s = (EdgeNode*)malloc(sizeof(EdgeNode));
        s->adjvex = i;
        s->next = G->adjlist[j].edgenext;
        G->adjlist[j].edgenext = s;
    }
}
void DispGraph(AdjMatrix* G)
{
    int i;
    for (i = 0; i < G->n; i++)
    {
        printf("%d->", i + 1);
        while (1)
        {
            if (G->adjlist[i].edgenext == NULL)
            {
                printf("^");
                break;
            }
            printf("%d->", G->adjlist[i].edgenext->adjvex + 1);
            //②
            G->adjlist[i].edgenext = G->adjlist[i].edgenext->next;

        }
        printf("\n");
    }
}
int main()
{
    AdjMatrix* G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
    CreateGraph(G);
    DispGraph(G);
}





/*
#include<iostream>
#define MAX_VERTEX_NUM 100
typedef char VertexType;
typedef int EdgeType;
using namespace std;
typedef struct {
	int vexnum;
	int edgenum;
	VertexType vex[MAX_VERTEX_NUM];
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;

void Create_MG(MGraph& G);
void Print_MG(MGraph& G);


int main() {
	MGraph G;

	Create_MG(G);
	Print_MG(G);
	return 0;
}

void Create_MG(MGraph& G) {
	cin >> G.vexnum >> G.edgenum;
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.edges[i][j] = 0;

	int a, b;
	for (int i = 0; i < G.edgenum; i++) {
		cin >> a >> b;
		G.edges[b][a] = G.edges[a][b] = 1;
	}
}

void Print_MG(MGraph& G) {
	cout << "Vertexnum: " << G.vexnum << endl;
	cout << "Edgenum:   " << G.edgenum << endl;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.edges[i][j] << " ";
		}
		cout << endl;
	}
}
*/
// 5 6 0 1 0 3 1 2 1 4 2 3 2 4 