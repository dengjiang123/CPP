#include"Dijkstra.h"
#include<iostream>
#include<string>

Graph_DG::Graph_DG(int vernum, int edgenum) {
	this->vernum = vernum;
	this->edgenum = edgenum;
	arc = new int* [vernum];
	for (int i = 0; i < vernum; i++) {
		arc[i] = new int[vernum];
		for (int j = 0; j < vernum; j++)
			arc[i][j] = INT_MAX;
	}
	dis = new Dis[vernum];
}

Graph_DG::~Graph_DG() {
	delete[] dis;
	for (int i = 0; i < vernum; i++)
		delete[] arc[i];
	delete arc;
}

void Graph_DG::Create_G() {
	int start, end, weight;
	for (int i = 0; i < edgenum; i++) {
		std::cin >> start >> end >> weight;
		arc[start - 1][end - 1] = weight;
	}
}

void Graph_DG::Print_G() {
	std::cout << "\nÁÚ½Ó¾ØÕó:\n";
	for (int i = 0; i < vernum; i++) {
		for (int j = 0; j < vernum; j++) {
			if (arc[i][j] == INT_MAX)
				std::cout << "¡Þ" << " ";
			else
				std::cout << arc[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Graph_DG::Dijkstra(int begin) {
	for (int i = 0; i < vernum; i++) {
		dis[i].path = "V" + std::to_string(begin) + "-->" + std::to_string(i);
		dis[i].value = arc[begin - 1][i];
	}
	dis[begin - 1].value = 0;
	dis[begin - 1].visited = true;
	for(int i=)
}