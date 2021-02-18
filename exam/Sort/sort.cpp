#include<iostream>
#include<vector>
using namespace std;
void InsertSort(vector<int>& x, int n);
void ShellSort(vector<int>& x, int n);
void BubbleSort(vector<int>& x, int n);

void QuickSort(vector<int>& x, int low, int high);
int Partition(vector<int>& x, int low, int high);

void BuildMaxHeap(vector<int>& x, int len);
void HeadAdjust(vector<int>& x, int k, int len);
void HeapSort(vector<int>& x, int len);

vector<int> B = { 0,49,38,65,97,76,13,27,49,55,4 };
void Merge(vector<int>& x, int low, int mid, int high);
void MergeSort(vector<int>& x, int low, int high);

void SelectSort(vector<int>& x, int n);
void show(const vector<int> x);
int main() {
	vector<int> x = { 0,49,38,65,97,76,13,27,49,55,4 };
	int n = x.size();
	show(x);
	MergeSort(x, 1, n);
	show(x);
}

void Merge(vector<int>& x, int low, int mid, int high) {
	int i, j, k;
	for (k = low; k <= high; k++)
		B[k] = x[k];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j])
			x[k] = B[i++];
		else
			x[k] = B[j++];
	}
	while (i <= mid)
		x[k++] = B[i++];
	while (j <= high)
		x[k++] = B[j++];
}

void MergeSort(vector<int>& x, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(x, low, mid);
		MergeSort(x, mid + 1, high);
		Merge(x, low, mid, high);
	}
}

void BuildMaxHeap(vector<int>& x, int len) {
	for (int i = len / 2; i > 0; i--)
		HeadAdjust(x, i, len);
}

void HeadAdjust(vector<int>& x, int k, int len) {
	x[0] = x[k];
	for (int i = 2 * k; i <= len; i *=2) {
		if (i < len && x[i] < x[i + 1])
			i++;
		if (x[0] >= x[i])
			break;
		else {
			x[k] = x[i];
			k = i;
		}
	}
	x[k] = x[0];
}

void HeapSort(vector<int>& x, int len) {
	BuildMaxHeap(x, len);
	for (int i = len; i > 1; i--) {
		x[0] = x[1];
		x[1] = x[i];
		x[i] = x[0];
		HeadAdjust(x, 1, i - 1);
	}
}

void SelectSort(vector<int>& x, int n) {
	int min;
	for (int i = 1; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (x[min] > x[j])
				min = j;
		if (min != i) {
			x[0] = x[i];
			x[i] = x[min];
			x[min] = x[0];
		}
	}
}

void QuickSort(vector<int>& x, int low, int high) {
	if (low < high) {
		int p = Partition(x, low, high);
		QuickSort(x, low, p - 1);
		QuickSort(x, p + 1, high);
	}
}

int Partition(vector<int>& x, int low, int high) {
	int p = x[low];
	while (low < high) {
		while (low < high && x[high] >= p)
			high--;
		x[low] = x[high];
		while (low < high && x[low] <= p)
			low++;
		x[high] = x[low];
	}
	x[low] = p;
	return low;
}

void InsertSort(vector<int>& x, int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (x[i] < x[i - 1]){
			x[0]=x[i];
			for (j = i - 1; x[0] < x[j]; j--)
				x[j + 1] = x[j];
			x[j + 1] = x[0];
			}
	}
}

void ShellSort(vector<int>& x, int n) {
	int dk, i, j;
	for (dk = n / 2; dk >= 1; dk /= 2) {
		for (i = dk + 1; i <= n; i++) {
			if (x[i] < x[i - dk]) {
				x[0] = x[i];
				for (j = i - dk; j > 0 && x[0] < x[j]; j -= dk)
					x[j + dk] = x[j];
				x[j + dk] = x[0];
			}
		}
	}
}

void BubbleSort(vector<int>& x, int n) {
	bool flag;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] > x[j]) {
				x[0] = x[j - 1];
				x[j - 1] = x[j];
				x[j] = x[0];
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}

void show(const vector<int> x) {
	int n = x.size();
	for (int i = 1; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}