#include<iostream>
#include<fstream>
#include<ctime>
#include"Dijkstra.h"
using namespace std;
int main() {
	clock_t start_t, end_t, temp_t;
	start_t = clock();
	int vernum, edgenum;
	ifstream fin("test.txt");
	fin >> vernum >> edgenum;
	Graph_DG G(vernum, edgenum);
	int start, end, weight;
	for (int i = 0; i < edgenum; i++) {
		fin >> start >> end >> weight;
		G.Create(start + 1, end + 1, weight);
	}
	//G.Dijkstra(100);
	//G.Print_Path(100);
	//G.Create_G();
	//G.Print_G();
	//G.Dijkstra(1);
	//G.Print_Path(1);
	
	G.Dijkstra(100);
	
	
	for (int i = 100; i <= 2500; i += 100)
		G.Print_Start_End(i);

	temp_t = clock();
	cout << temp_t - start_t << " ms\n";
	cout << endl << endl << "#########################################################################" << endl << endl;
	G.Flord();
	G.Print_Flord(100);

	std::cout << INT_MAX << std::endl;
	end_t = clock();
	cout << end_t - temp_t << " ms\n";
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