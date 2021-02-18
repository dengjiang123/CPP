#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	vector<char> x;
	char ch;
	ch = getchar();
	
	while (ch != 'A') {
		if (ch == '#') {
			x.pop_back();
		}
		else if (ch == '@') {
			while (!(x[x.size() - 1] == ' ')) {
				x.pop_back();
			}
		}
		else
			x.push_back(ch);
		ch = getchar();
	}

	for (int i = 0; i < x.size(); i++) {
		cout << x[i];
	}
}