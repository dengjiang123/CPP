#include<iostream>
using namespace std;
#define MaxSize 100

typedef struct {
	int* data;
	int length;
}SeqList;
bool ListInsert(SeqList& L, int i, int e);
bool ListDelete(SeqList& L, int i, int& e);
int LocateElem(SeqList L, int e);

bool DeleteMin(SeqList& L, int& e);
void Reverse(SeqList& L);
void Delete_x_same(SeqList& L, int x);
bool Delete_s_t(SeqList& L, int s, int t);
bool Delete_same(SeqList& L);
bool Merge_Sort(SeqList& L1, SeqList& L2, SeqList& L);
void Exchange(SeqList& L, int m, int n);
void SearchExchangeInsert(SeqList& L, int x);
void Reverse_p(SeqList& L, int p);
int M_Search(SeqList& L1, SeqList& L2);
int M_Search_improve(SeqList& L1, SeqList& L2);
int Majority(SeqList& L);
int FindMissMin(SeqList& L);
void show(SeqList L);

int main() {
	SeqList L;
	L.length = 8;
	L.data = new int[MaxSize] {0, 5, 5, 3, 5, 7, 5, 7};

	cout << Majority(L) << endl;
	show(L);
	return 0;
}

void show(SeqList L) {
	cout << L.length << ": ";
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

bool ListInsert(SeqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length += 1;
	return true;
}

bool ListDelete(SeqList& L, int i, int& e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length -= 1;
	return true;
}

int LocateElem(SeqList L, int e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

bool DeleteMin(SeqList& L, int& e) {
	int t = 0;
	if (L.length == 0)
		return false;
	for (int i = 1; i < L.length; i++)
		if (L.data[t] >= L.data[i])
			t = i;
	e = L.data[t];
	L.data[t] = L.data[L.length - 1];
	L.length -= 1;
	return true;
}

void Reverse(SeqList& L) {
	int temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

void Delete_x_same(SeqList& L, int x) {
	int number = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[number] = L.data[i];
			number += 1;
		}
	}
	L.length = number;
}

bool Delete_s_t(SeqList& L, int s, int t) {
	if (L.length == 0 || s >= t)
		return false;
	int number = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] <= s || L.data[i] >= t) {
			L.data[number] = L.data[i];
			number += 1;
		}
	}
	L.length = number;
}

bool Delete_same(SeqList& L) {
	if (L.length == 0)
		return false;
	int sum = 0;
	for (int i = 1; i < L.length; i++)
		if (L.data[sum] != L.data[i])
			L.data[++sum] = L.data[i];
	L.length = sum + 1;
	return true;
}

bool Merge_Sort(SeqList& L1, SeqList& L2, SeqList& L) {
	int sum = L1.length + L2.length;
	if (sum > MaxSize)
		return false;
	int m, n;
	m = 0;
	n = 0;
	int s = 0;
	while (L1.length > m && L2.length > n) {
		if (L1.data[m] <= L2.data[n])
			L.data[s++] = L1.data[m++];
		else
			L.data[s++] = L2.data[n++];
	}
	while (L1.length > m)
		L.data[s++] = L1.data[m++];
	while (L2.length > n)
		L.data[s++] = L2.data[n++];
	L.length = s;
	return true;
}

void Exchange(SeqList& L, int m, int n) {
	int temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
	for (int i = 0; i < n / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[n - i - 1];
		L.data[n - i - 1] = temp;
	}
	for (int i = 0; i < m / 2; i++) {
		temp = L.data[i + n];
		L.data[i + n] = L.data[m + n - i - 1];
		L.data[m + n - i - 1] = temp;
	}
}

void SearchExchangeInsert(SeqList& L, int x) {
	int n = L.length;
	int start = 0;
	int end = n - 1;
	while (L.data[(start + end) / 2] != x && start + 1 != end) {
		//cout << start << " " << end << endl;
		if (L.data[(start + end) / 2] > x)
			end = (start + end) / 2;
		else if (L.data[(start + end) / 2] < x)
			start = (start + end) / 2;
	}
	//cout << start << " " << end << endl;
	int temp;
	if (L.data[(start + end) / 2] == x) {
		temp = L.data[(start + end) / 2];
		L.data[(start + end) / 2] = L.data[(start + end) / 2 + 1];
		L.data[(start + end) / 2 + 1] = temp;
	}
	else {
		int i = 0;
		for (i = L.length - 1; L.data[i] > x && i >= 0; i--) 
			L.data[i + 1] = L.data[i];
		L.data[i + 1] = x;
		L.length += 1;
	}
}

void Reverse_p(SeqList& L, int p) {
	int* temp = new int[p];
	for (int i = 0; i < p; i++)
		temp[i] = L.data[i];
	for (int i = p; i < L.length; i++)
		L.data[i - p] = L.data[i];
	for (int i = p - 1; i >= 0; i--)
		L.data[L.length - p + i] = temp[i];
	delete[]temp;
}

int M_Search(SeqList& L1, SeqList& L2) {
	int middle = 0;
	int sum = (L1.length + L2.length - 2) / 2;
	int m = 0;
	int n = 0;
	for (int i = 0; i <= sum; i++) {
		if (m < L1.length && n < L2.length && L1.data[m] <= L2.data[n]) {
			middle = L1.data[m];
			m++;
		}
		else if (m < L1.length && n < L2.length && L1.data[m] > L2.data[n]) {
			middle = L2.data[n];
			n++;
		}
		else if (m == L1.length) {
			middle = L2.data[n];
			n++;
		}
		else if (n == L2.length) {
			middle = L1.data[m];
			m++;
		}
		cout << middle << " ";
	}
	cout << endl;
	return middle;
}

int M_Search_improve(SeqList& L1, SeqList& L2) {      //!!!!!!!!!!!!!!!!!!!!!
	int s1 = 0, d1 = L1.length - 1, m1, s2 = 0, d2 = L2.length - 1, m2;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		cout << m1 << " " << m2 << endl;
		if (L1.data[m1] == L2.data[m2])
			return L1.data[m1];
		if (L1.data[m1] < L2.data[m2]) {
			if ((s1 + d1) % 2 == 0) {
				s1 = m1;
				d2 = m2;
			}
			else {
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else {
			if ((s2 + d2) % 2 == 0) {
				d1 = m1;
				s2 = m2;
			}
			else {
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return L1.data[s1] < L2.data[s2] ? L1.data[s1] : L2.data[s2];
}

int Majority(SeqList& L) {
	int n = L.length;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (L.data[i] > L.data[j]) {
				temp = L.data[i];
				L.data[i] = L.data[j];
				L.data[j] = temp;
			}
		}
	}
	temp = L.data[n / 2];
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (L.data[i] == temp)
			sum += 1;
	if (sum > n / 2)
		return sum;
	else
		return -1;
}

int FindMissMin(SeqList& L) {
	int n = L.length;
	int temp = 1;
	for (int i = 0; i < n; i++) {

	}
	return -1;
}