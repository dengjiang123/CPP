
#include<iostream>
#include<ctime>
using namespace std;
int fac(int n);
int main() {
	clock_t a, b;
	a = clock();
	for (int i = 1; i <= 40; i++) {
		cout << i << " " << fac(i) << endl;
	}
	b = clock();
	cout << b - a << endl;
	//system("pause");
	return 0;
}

int fac(int n) {
	if (n <= 1)
		return 1;
	else
		return fac(n - 1) + fac(n - 2);
}


/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
int f(int n);
int main() {
	clock_t start = clock();
	for (int i = 1; i <= 40; i++) {
		printf("%d %d\n", i, f(i));
	}
	clock_t end = clock();
	printf("%d\n", end - start);
	return 0;
}

int f(int n) {
	if (n <= 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}
*/

/*
#include<iostream>
#include<ctime>
using namespace std;
int fac(int n);
int main() {
	int n;
	cin >> n;
	clock_t a, b;
	a = clock();
	for (int i = 0; i <= n; i++) {
		cout << i << " " << fac(i) << endl;
	}
	b = clock();
	cout << b - a << endl;
	//system("pause");
	return 0;
}

int fac(int n) {
	if (n <= 1)
		return 1;
	else
		return fac(n - 1) + fac(n - 2);
}
*/



//6-1 单链表逆转 (20分)
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); // 细节在此不表 
void Print(List L); // 细节在此不表 

List Reverse(List L);

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

List Read() {
	List L, p, ne;
	int n;
	int t;
	scanf("%d", &n);
	if (n == 0)
		return NULL;
	scanf("%d", &t);
	ne = (Node*)malloc(sizeof(Node));
	ne->Next = NULL;
	ne->Data = t;
	L = ne;
	p = ne;
	for (int i = 1; i < n; i++) {
		ne = (Node*)malloc(sizeof(Node));
		p->Next = ne;
		scanf("%d", &t);
		ne->Data = t;
		ne->Next = NULL;
		p = ne;
	}
	return L;
}

void Print(List L) {
	List p = L;
	while (p) {
		printf("%d ", p->Data);
		p = p->Next;
	}
	printf("\n");
}

List Reverse(List L) {
	List p, q;
	p = L;
	L = NULL;
	while (p) {
		q = p;
		p = p->Next;
		q->Next = L;
		L = q;
	}
	return L;
}
*/

/*
List Reverse(List L) {
	List p = L;
	List ne;
	List La = NULL;
	while (p) {
		ne = (List)malloc(sizeof(PtrToNode));
		if (La == NULL) {
			La = ne;
			La->Data = p->Data;
		}
		else {
			ne->Next = La;
			ne->Data = p->Data;
			La = ne;
		}
		p = p->Next;
	}
	return La;
}
*/

/*
List Reverse(List L) {
	List p = L;
	List ne;
	List La = NULL;
	while (p) {
		ne = (Node*)malloc(sizeof(Node));
		if (La == NULL) {
			La = ne;
			La->Data = p->Data;
		}
		else {
			ne->Next = La;
			ne->Data = p->Data;
			La = ne;
		}
		p = p->Next;
	}
	return La;
}
*/

//5
//1 3 4 5 2

//1073 多选题常见计分法 (20分)
/*
#include<iostream>
#include<vector>
using namespace std;
typedef struct mark {
	int points;
	int number;
	int correctnum;
	vector<char> option;
};
int judge(int i, char ch);
mark* library;
int main() {
	int N, M;
	cin >> N >> M;
	int point, num, correct;
	char ch;
	library = new mark[M];
	
	for (int i = 0; i < M; i++) {
		cin >> point >> num >> correct;
		library[i].points = point;
		library[i].number = num;
		library[i].correctnum = correct;
		for (int j = 0; j < correct; j++) {
			cin.get();
			ch = cin.get();
			library[i].option.push_back(ch);
		}
		
	}

	double poin;
	int f;
	for (int i = 0; i < N; i++) {
		poin = 0;
		f = 0;
		for (int j = 0; j < M; j++) {
			cin.get();
			cin.get();
			cin >> num;
			for (int k = 0; k < num; k++) {
				cin.get();
				ch = cin.get();
				if (judge(j, ch));
			}
		}
	}

	
}

int judge(int i, char ch) {

}
*/




//1022 D进制的A+B (20分)
/*
#include<iostream>
#include<stack>
using namespace std;
int main() {
	int A, B, D;
	cin >> A >> B >> D;
	int all = A + B;
	if (!all) {
		cout << 0 << endl;
		return 0;
	}
	stack<int> S;
	while (all) {
		S.push(all % D);
		all /= D;
	}
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}
*/



//1017 A除以B (20分)
/*
#include<iostream>
using namespace std;
int main() {
	string A;
	int B;
	cin >> A >> B;
	if (A.length() == 1 && (A[0] - '0') < B) {
		cout << 0 << " " << A[0] << endl;
		return 0;
	}
	int R = 0;
	if ((A[0] - '0') < B)
		R = A[0] - '0';
	else {
		cout << (A[0] - '0') / B;
		R = (A[0] - '0') % B;
	}
	for (int i = 1; i < A.length(); i++) {
		cout << (R * 10 + A[i] - '0') / B;
		R = (R * 10 + A[i] - '0') % B;
	}
	cout << " " << R << endl;
}
*/


//1027 打印沙漏 (20分)
/*
* 
#include<iostream>
using namespace std;
int main() {
	int n;
	char ch;
	cin >> n;
	cin.get();
	ch = cin.get();
	int start = -1;
	int all = -1;
	while (all <= n) {
		start += 2;
		all += 2 * start;
	}
	all -= 2 * (start);
	start -= 2;
	int last = n - all;
	for (int i = 1; i <= start / 2; i++) {
		for (int j = 1; j < i; j++)
			cout << " ";
		for (int j = 1; j <= start - i * 2 + 2; j++)
			cout << ch;
		cout << endl;
	}

	for (int i = 1; i <= start / 2 + 1; i++) {
		for (int j = 1; j <= start / 2 - i + 1; j++)
			cout << " ";
		for (int j = 1; j <= i * 2 - 1; j++)
			cout << ch;
		cout << endl;
	}
	cout << last << endl;
}

*/