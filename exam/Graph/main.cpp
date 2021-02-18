#include<iostream>
#include"Dijkstra.h"
using namespace std;

int main() {
	int vernum, edgenum;
	cin >> vernum >> edgenum;
	Graph_DG G(vernum, edgenum);
	G.Create_G();
	G.Print_G();
}

/*
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
*/