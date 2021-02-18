#include<iostream>
class np {
private:
	double** p;
	int m;
	int n;
public:
	np(int a, int b);
	void random_np(int low = 0, int hig = 100);
	void show_np();
	int rank_np();
	np dot(np B);
};