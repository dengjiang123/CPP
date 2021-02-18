

//1062 最简分数 (20分)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	int n1, m1, n2, m2, k;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	if (n1 * m2 > n2 * m1) {
		swap(n1, n2);
		swap(m1, m2);
	}
	int num = 1;
	bool flag = false;
	while (n1 * k >= m1 * num) num++;
	while (n1 * k < m1 * num && m2 * num < n2 * k) {
		if (gcd(num, k) == 1) {
			printf("%s%d/%d", flag == true ? " " : "", num, k);
			flag = true;
		}
		num++;
	}
	return 0;
}
/*
#include<iostream>
using namespace std;
int main() {
	int a, b, c, d, e;
	char temp;
	cin >> a >> temp >> b >> c >> temp >> d >> e;
	if (1.0 * a / b < 1.0 * c / d)
		cout << int(1.0 * a / b * e + 0.5) << "/" << e << " " << int(1.0 * c / d * e + 0.5) << "/" << e << endl;
	else
		cout << int(1.0 * c / d * e + 0.5) << "/" << e << " " << int(1.0 * a / b * e + 0.5) << "/" << e << endl;
	return 0;
}
*/




//1077 互评成绩计算 (20分)
/*
#include<iostream>
using namespace std;
int main() {
	int n, Max;
	cin >> n >> Max;
	double* temp = new double[n];
	double last;
	int Ma, Mi, f;
	for (int i = 0; i < n; i++) {
		last = f = Ma = Mi = 0;
		for (int j = 0; j < n; j++)
			cin >> temp[j];
		for (int j = 1; j < n; j++) {
			if (temp[j] >= 0 && temp[j] <= Max) {
				if (Ma == 0 && Mi == 0)
					Ma = Mi = j;
				else {
					if (temp[j] > temp[Ma])
						Ma = j;
					if (temp[j] < temp[Mi])
						Mi = j;
				}
			}
		}
		for (int j = 1; j < n; j++) {
			if (temp[j] >= 0 && temp[j] <= Max && j != Ma && j != Mi) {
				last += temp[j];
				f++;
			}
		}
		last = (last / f + temp[0]) / 2;
		cout << int(last + 0.5) << endl;
	}
}
*/
/*
* 柳婼大神
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int g2, g1 = 0, cnt = -2, temp, maxn = -1, minn = m + 1;
		cin >> g2;
		for (int j = 0; j < n - 1; j++) {
			cin >> temp;
			if (temp >= 0 && temp <= m) {
				if (temp > maxn) maxn = temp;
				if (temp < minn) minn = temp;
				g1 += temp;
				cnt++;
			}
		}
		cout << int((((g1 - minn - maxn) * 1.0 / cnt) + g2) / 2 + 0.5) << endl;
	}
	return 0;
}
*/
/*
#include<iostream>
#include<iomanip>
using namespace std;
int judge(double* mark, int n, int j, int Max);
int main() {
	int n, Max;
	cin >> n >> Max;
	double** mark = new double* [n];
	double* last = new double[n];
	for (int i = 0; i < n; i++) {
		last[i] = 0;
		mark[i] = new double[n];
		for (int j = 0; j < n; j++)
			cin >> mark[i][j];
	}
	int f = 0;
	for (int i = 0; i < n; i++) {
		f = 0;
		for (int j = 1; j < n; j++)
			if (judge(mark[i], n, j, Max)) {
				last[i] += mark[i][j];
				f++;
			}
		last[i] /= f;
		last[i] = (last[i] + mark[i][0]) / 2;
	}
	for (int i = 0; i < n; i++)
		cout << fixed << setprecision(0) << last[i] << endl;
}

int judge(double* mark, int n, int j, int Max) {
	int Ma, Mi;
	Mi = Ma = 0;
	for (int a = 1; a < n; a++) {
		if (mark[a] >= 0 && mark[a] <= Max) {
			if (Mi == 0 && Ma == 0)
				Ma = Mi = a;
			else {
				if (mark[a] > mark[Ma])
					Ma = a;
				if (mark[a] < mark[Mi])
					Mi = a;
			}
		}
	}
	if (mark[j] >= 0 && mark[j] <= Max && j != Ma && j != Mi)
		return 1;
	return 0;
}
*/



//1005 Spell It Right (20分)
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string* name = new string[10];
	name[0] = "zero";
	name[1] = "one";
	name[2] = "two";
	name[3] = "three";
	name[4] = "four";
	name[5] = "five";
	name[6] = "six";
	name[7] = "seven";
	name[8] = "eight";
	name[9] = "nine";
	int sum = 0;
	char ch = '\n';
	do {
		ch = cin.get();
		if (ch >= '0' && ch <= '9')
			sum += (ch - '0');
	} while (ch != '\n');
	vector<int> all;
	if (!sum)
		all.push_back(0);
	while (sum) {
		all.push_back(sum % 10);
		sum /= 10;
	}
	for (int i = all.size() - 1; i > 0; i--) {
		cout << name[all[i]] << " ";
	}
	if (all.size())
		cout << name[all[0]] << endl;
}
*/



//1001 A+B Format (20分)
/*
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int a = x + y;
	if (a < 0) {
		cout << "-";
		a = abs(a);
	}
	vector<int> num;
	while (a) {
		num.push_back(a % 10);
		a /= 10;
	}
	int n = num.size();
	for (int i = n - 1; i >= 0; i--) {
		cout << num[i];
		if (i % 3 == 0 && i && n >= 4)
			cout << ",";
	}
	if (!n)
		cout << 0 << endl;
}
*/



//1030 完美数列 (25分)
/*
#include<iostream>
using namespace std;
typedef long long LL;
void sort(LL* p, LL n);
LL count_N(LL* p, LL n, LL B, LL i);
int main() {
	LL n, p;
	cin >> n >> p;
	LL* num = new LL[n];
	for (LL i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, n);
	LL Max = 0;
	for (LL i = 0; i < n; i++) {
		Max = (Max >= count_N(num, n, p, i) ? Max : count_N(num, n, p, i));
	}
	cout << Max << endl;
}

LL count_N(LL* p, LL n, LL B, LL i) {
	LL c = 0;
	for (int j = i; j < n; j++) {
		if (p[j] <= B * p[i]) {
			c++;
		}
		else
			break;
	}
	return c;
}

void sort(LL* p, LL n) {
	LL temp;
	for (LL i = 0; i < n; i++) {
		for (LL j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
*/




//1037 在霍格沃茨找零钱 (20分)
/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long LL;
int main() {
	int a, b, c;
	int x, y, z;
	scanf("%d.%d.%d", &a, &b, &c);
	scanf("%d.%d.%d", &x, &y, &z);
	LL x1, x2;
	x1 = a * 17 * 29 + b * 29 + c;
	x2 = x * 17 * 29 + y * 29 + z;
	LL last = x2 - x1;
	if (last < 0) {
		cout << "-";
		last = abs(last);
	}
	cout << last / (17 * 29) << ".";
	last %= (17 * 29);
	cout << last / 29 << ".";
	last %= 29;
	cout << last << endl;
}
*/




//1028 人口普查 (20分)
/*
#include<iostream>
#include<string>
using namespace std;
typedef struct person {
	string name;
	int year;
}person;
int main() {
	int n;
	cin >> n;
	int a, b, c, all;
	string temp;
	person Max, Min;
	int s = 0;
	int f = 1;
	for (int i = 0; i < n; i++) {
		cin.get();
		cin >> temp >> a;
		cin.get();
		cin >> b;
		cin.get();
		cin >> c;
		all = a * 10000 + b * 100 + c;
		if (all <= 20140906 && all >= 18140906) {
			s++;
			if (f) {
				Max.name = Min.name = temp;
				Max.year = Min.year = all;
				f = 0;
			}
			if (Max.year > all && !f) {
				Max.name = temp;
				Max.year = all;
			}
			if (Min.year < all && !f) {
				Min.name = temp;
				Min.year = all;
			}
		}
	}
	if (!s) {
		cout << 0 << endl;
		return 0;
	}
	cout << s << " " << Max.name << " " << Min.name << endl;
}
*/



/*
#include<iostream>
#include<string>
using namespace std;
typedef struct person {
	string name;
	int year, month, day;
};
int judge(person pe);
void exchange(person& pe, person& pe1);
int compare(person& pe, person& pe1);
int main() {
	int n;
	cin >> n;
	int s = 0;
	int f = 1;
	person Max, Min, p;
	for(int i=0;i<n;i++){
		cin.get();
		cin >> p.name >> p.year;
		cin.get();
		cin >> p.month;
		cin.get();
		cin >> p.day;
		if (judge(p)) {
			if (f) {
				exchange(Max, p);
				exchange(Min, p);
				f = 0;
			}
			else if (compare(Min, p))
				exchange(Min, p);
			else if (compare(p, Max))
				exchange(Max, p);
			s++;
		}
	}
	if (s == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << s << " " << Max.name << " " << Min.name << endl;
}

void exchange(person& pe, person& pe1) {
	pe.name = pe1.name;
	pe.year = pe1.year;
	pe.month = pe1.month;
	pe.day = pe.day;
}

int compare(person& pe, person& pe1) {
	if (pe.year < pe1.year)
		return 1;
	else if (pe.year == pe1.year && pe.month < pe1.month)
		return 1;
	else if (pe.year == pe1.year && pe.month == pe1.month && pe.day <= pe1.day)
		return 1;
	else
		return 0;
}

int judge(person pe) {
	if (pe.year > 1814 && pe.year < 2014)
		return 1;
	else if (pe.year == 1814 && pe.month > 9)
		return 1;
	else if (pe.year == 1814 && pe.month == 9 && pe.day >= 6)
		return 1;
	else if (pe.year == 2014 && pe.month < 9)
		return 1;
	else if (pe.year == 2014 && pe.month == 9 && pe.day <= 6)
		return 1;
	else
		return 0;
}
*/




//1008 数组元素循环右移问题 (20分)
/*
#include<iostream>
using namespace std;
void Move(int* p, int n, int m);
int main() {
	int n, m;
	cin >> n >> m;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int temp = m % n;
	Move(p, n, temp);
	int i;
	for (i = 0; i < n-1; i++) 
		cout << p[i] << " ";
	cout << p[i] << endl;
}

void Move(int* p, int n, int m) {
	int* temp = new int[m];
	for (int i = n - 1; i >= n - m; i--) {
		temp[i - n + m] = p[i];
	}
	for (int i = n - m - 1; i >= 0; i--) {
		p[i + m] = p[i];
	}
	for (int i = 0; i < m; i++) {
		p[i] = temp[i];
	}
}
*/


//1083 是否存在相等的差 (20分)
/*
#include<iostream>
#include<vector>
using namespace std;
typedef struct num {
	int value;
	int n = 0;
}num;
void Sort(vector<num>& t);
int main() {
	int n, temp;
	cin >> n;
	int* t = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		t[i] = abs(temp - i - 1);
	}
	int f = 1;
	vector<num> An;
	num test;
	for (int i = 0; i < n; i++) {
		f = 1;
		for (int j = 0; j < An.size(); j++) {
			if (An[j].value == t[i]) {
				An[j].n++;
				f = 0;
			}
		}
		if (f) {
			test.value = t[i];
			test.n = 1;
			An.push_back(test);
		}
	}
	Sort(An);
	for (int i = 0; i < An.size(); i++) {
		if (An[i].n > 1)
			cout << An[i].value << " " << An[i].n << endl;
	}
}

void Sort(vector<num>& t) {
	num temp;
	for (int i = 0; i < t.size(); i++) {
		for (int j = i + 1; j < t.size(); j++) {
			if (t[i].value < t[j].value) {
				temp.value = t[i].value;
				temp.n = t[i].n;
				t[i].value = t[j].value;
				t[i].n = t[j].n;
				t[j].value = temp.value;
				t[j].n = temp.n;
			}
		}
	}
}
*/




//1057 数零壹 (20分)
/*
#include<iostream>
using namespace std;
int main() {
	long long s = 0;
	char ch;
	do {
		ch = cin.get();
		if (ch >= 'a' && ch <= 'z')
			s += (ch - 'a' + 1);
		else if (ch >= 'A' && ch <= 'Z')
			s += (ch - 'A' + 1);

	} while (ch != '\n');
	int a1, a0;
	a1 = a0 = 0;
	while (s) {
		if (s % 2)
			a1++;
		else
			a0++;
		s /= 2;
	}
	cout << a0 << " " << a1 << endl;
}
*/



/*
#include<iostream>
#include<ctime>
using namespace std;
typedef long long LL;
LL  Sim(LL  a, LL  b);
LL Sim2(LL a, LL b);
int a1 = 0;
int a2 = 0;
int main() {
	cout << LLONG_MAX << endl;
	int a, b;
	srand(time(NULL));
	a = rand();
	b = rand();
	cout << a << " " << b << endl;
	clock_t t1, t2, t3;
	t1 = clock();
	cout << Sim(a, b) << endl;
	t2 = clock();
	cout << Sim2(a, b) << endl;
	t3 = clock();
	cout << t2 - t1 << " " << t3 - t2 << endl;
	cout << a1 << " " << a2 << endl;
}
LL Sim2(LL a, LL b) {
	a2++;
	return b == 0 ? a : Sim2(b, a % b);
}

LL  Sim(LL  a, LL  b) {
	if (a == 0)
		return 1;
	LL  x = abs(a);
	LL  y = abs(b);
	LL  Min = x;
	if (x > y)
		Min = y;
	LL  i;
	for (i = Min; i > 1; i--) {
		a1++;
		if (x % i == 0 && y % i == 0)
			break;
	}
	return i;
}
*/


//1034 有理数四则运算 (20分)
/*
#include<iostream>
using namespace std;
long long Sim(long long a, long long b);
void Show(long long x, long long y);
void Show_Ans(long long a, long long b, long long c, long long d, int i);
int main() {
	long long  x1, x2, x3, x4;
	char temp;
	long long  t;
	cin >> x1 >> temp >> x2 >> x3 >> temp >> x4;
	t = Sim(x1, x2);
	x1 /= t;
	x2 /= t;
	t = Sim(x3, x4);
	x3 /= t;
	x4 /= t;

	for (int i = 0; i < 4; i++) {
		if (x1 < 0)
			cout << "(";
		Show(x1, x2);
		if (x1 < 0)
			cout << ")";

		if (i == 0)
			cout << " + ";
		else if (i == 1)
			cout << " - ";
		else if (i == 2)
			cout << " * ";
		else
			cout << " / ";

		if (x3 < 0)
			cout << "(";
		Show(x3, x4);
		if (x3 < 0)
			cout << ")";
		cout << " = ";
		Show_Ans(x1, x2, x3, x4, i);
		cout << endl;
	}
}

void Show_Ans(long long  a, long long  b, long long  c, long long d, int i) {
	long long  na, nc;
	long long  s, e;
	na = a * d;
	nc = c * b;
	e = d * b;
	if (i == 3) {
		if (nc == 0) {
			cout << "Inf";
			return;
		}
		if (nc < 0) {
			s = -na;
			e = -nc;
		}
		else {
			s = na;
			e = nc;
		}
	}
	else if (i == 0)
		s = na + nc;
	else if (i == 1)
		s = na - nc;
	else if (i == 2) {
		s = na * nc;
		e *= e;
	}
	long long  t = Sim(s, e);
	s /= t;
	e /= t;
	if (s < 0)
		cout << "(";
	Show(s, e);
	if (s < 0)
		cout << ")";
}

long long  Sim(long long  a, long long  b) {
	return abs(b == 0 ? a : Sim(b, a % b));
}


long long  Sim(long long  a, long long  b) {
	if (a == 0)
		return 1;
	long long  x = abs(a);
	long long  y = abs(b);
	long long  Min = x;
	if (x > y)
		Min = y;
	long long  i;
	for (i = Min; i > 1; i--)
		if (x % i == 0 && y % i == 0)
			break;
	return i;
}


void Show(long long  x, long long  y) {
	if (x == 0) {
		cout << 0;
		return;
	}
	if (abs(x) >= abs(y)) {
		if (x % y != 0) {
			cout << x / y << " ";
			if (x > 0)
				cout << x % y << "/" << y;
			else
				cout << abs(x) % y << "/" << y;
		}
		else
			cout << x / y;
	}
	else
		cout << x << "/" << y;
}

*/


/*
#include<iostream>
using namespace std;
void Show(int x, int y);
void Show_Ans(int a, int b, int c, int d, int i);
void Simplify(int* x, int* y);
int min_num(int a, int b);
int main() {
	int x1, x2, x3, x4;
	char ch;
	cin >> x1 >> ch >> x2 >> x3 >> ch >> x4;
	Simplify(&x1, &x2);
	Simplify(&x3, &x4);
	for (int i = 0; i < 4; i++) {
		if (x1 < 0)
			cout << "(";
		Show(x1, x2);
		if (x1 < 0)
			cout << ")";

		if (i == 0)
			cout << " + ";
		else if (i == 1)
			cout << " - ";
		else if (i == 2)
			cout << " * ";
		else
			cout << " / ";

		if (x3 < 0)
			cout << "(";
		Show(x3, x4);
		if (x3 < 0)
			cout << ")";
		cout << " = ";
		Show_Ans(x1, x2, x3, x4, i);
		cout << endl;
	}
}

int min_num(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

void Simplify(int* x, int* y) {
	if (*y == 0 || *x == 0)
		return;
	int a, b;
	a = abs(*x);
	b = abs(*y);
	int Min;
	int f = 2;
	while (f < min_num(a, b)) {
		if (a % f == 0 && b % f == 0) {
			a /= f;
			b /= f;
		}
		else
			f++;
	}
	Min = min_num(a, b);
	if (a % Min == 0 && b % Min == 0) {
		a /= Min;
		b /= Min;
	}
	*y = b;
	if (*x < 0)
		*x = -a;
	else
		*x = a;
}

void Show_Ans(int a, int b, int c, int d, int i) {
	int na, nc;
	int s, e;
	na = a * d;
	nc = c * b;
	e = d * b;
	if (i == 3) {
		if (nc == 0) {
			cout << "Inf";
			return;
		}
		if (nc < 0) {
			s = -na;
			e = abs(nc);
		}
		else {
			s = na;
			e = nc;
		}
	}
	else if (i == 0)
		s = na + nc;
	else if (i == 1)
		s = na - nc;
	else if (i == 2) {
		s = na * nc;
		e *= e;
	}
	Simplify(&s, &e);
	if (s < 0)
		cout << "(";
	Show(s, e);
	if (s < 0)
		cout << ")";
}

void Show(int x, int y) {
	if (x == 0) {
		cout << 0;
		return;
	}
	if (abs(x) >= abs(y)) {
		if (x % y != 0) {
			cout << x / y << " ";
			if (x > 0)
				cout << x % y << "/" << y;
			else
				cout << abs(x) % y << "/" << y;
		}
		else
			cout << x / y;
	}
	else
		cout << x << "/" << y;
}
*/
//2/3 -4/2



//1023 组个最小数 (20分)
/*
#include<iostream>
using namespace std;
int main() {
	int temp;
	int t = 0;
	int f = 0;
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		if (i == 0 && temp == 0)
			f = 1;
		else if (i == 0 && temp != 0)
			t = temp;
		else if (f == 0 && temp != 0) {
			cout << i;
			for (int j = 0; j < t; j++)
				cout << 0;
			for (int j = 1; j < temp; j++)
				cout << i;
			f = 1;
		}
		else if (f)
			for (int j = 0; j < temp; j++)
				cout << i;
	}
	return 0;
}

*/


//1019 数字黑洞 (20分)
/*
#include<iostream>
using namespace std;
void Sort(int* p);
void Reverse(int* p);
int To_number(int* p);
void New_num(int* p, int n);
int main() {
	int* num = new int[4]{ 0,0,0,0 };
	int temp;
	cin >> temp;
	New_num(num, temp);

	int Max, Min, ans;
	do {
		Sort(num);
		Min = To_number(num);
		Reverse(num);
		Max = To_number(num);
		ans = Max - Min;
		cout << Max << " - ";
		if (Min < 10)
			cout << "000";
		else if (Min < 100)
			cout << "00";
		else if (Min < 1000)
			cout << "0";
		cout << Min << " = ";
		if (ans < 10)
			cout << "000";
		else if (ans < 100)
			cout << "00";
		else if (ans < 1000)
			cout << "0";
		cout<< ans << endl;
		if (ans == 0)
			break;
		New_num(num, ans);

	} while (ans != 6174);
	return 0;
}

void Sort(int* p) {
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (p[i] > p[j]) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void Reverse(int* p) {
	int temp;
	temp = p[0];
	p[0] = p[3];
	p[3] = temp;
	temp = p[1];
	p[1] = p[2];
	p[2] = temp;
}

int To_number(int* p) {
	int s = 0;
	for (int i = 0; i < 4; i++) {
		s = s * 10 + p[i];
	}
	return s;
}

void New_num(int* p, int n) {
	for (int i = 0; i < 4; i++) {
		p[i] = n % 10;
		n /= 10;
	}
}

*/



/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	int num[6];
	int temp = 0;
	char ch;
	for (int i = 0; i < T; i++) {
		getchar();
		for (int j = 0; j < 6; j++) {
			ch = getchar();
			num[j] = ch - '0';
		}
		scanf("%d", temp);
		if (temp >= 1 && num[5] >= 7)
			num[4] += 1;
		for (int j = 0; j < 6; j++)
			printf("%d", num[j]);
		printf("\n");
	}
}
*/


/*
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	printf("1");
	for (int i = 1; i < n; i++)
		printf("0");
	return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char ch[] = "sulqw wkh ohqjwk ri wklv vhqwhqfh";
	int n = strlen(ch);
	for (int i = 0; i < n; i++) {
		if (ch[i] >= 'd' && ch[i] != ' ')
			ch[i] -= 3;
		else if (ch[i] < 'd' && ch[i] != ' ')
			ch[i] += (26 - 3);
	}
	printf("%s", ch);
}

*/