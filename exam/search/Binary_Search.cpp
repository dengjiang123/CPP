#include<iostream>
#include<vector>
using namespace std;
int Binary_Search(vector<int>& S, int key);
int main() {
	vector<int> s = { 7,10,13,16,19,29,32,33,37,41,43 };
	cout << Binary_Search(s, 19) << endl;
	cout << Binary_Search(s, 15) << endl;
}

int Binary_Search(vector<int>& S, int key) {
	int low = 0;
	int high = S.size() - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (S[mid] == key)
			return mid;
		else if (S[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}