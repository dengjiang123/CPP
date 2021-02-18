#pragma once

#include<iostream>
#include<string>

struct Dis {
	std::string path;
	int value;
	bool visited;
	Dis() {
		value = 0;
		visited = false;
		path = "";
	}
};

class Graph_DG {
private:
	int vernum;
	int edgenum;
	int** arc;
	Dis* dis;
public:
	Graph_DG(int vernum, int edgenum);
	~Graph_DG();
	void Create_G();
	void Print_G();
	void Dijkstra(int begin);
};