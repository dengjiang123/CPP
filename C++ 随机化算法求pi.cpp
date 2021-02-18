
#include<iostream>
#include<random>
#include<vector>
using namespace std;

// 圆周率求到 10^-10


default_random_engine e;
uniform_real_distribution<long double> u(0.0, 1.0);

void pai(int n, int precise, vector<int>& result)
{

	int k = 0;//落入圆内次数
	int n1 = n;
	while (n1 > 0)
	{
		double x1 = u(e);
		double y1 = u(e);
		//cout << x1 << "    " << y1 << endl;
		if (x1 * x1 + y1 * y1 <= 1)
		{
			k++;
		}
		n1--;
	}
	cout << "k=" << k << endl;

	int a = 4 * k / n; //整数部分
	int yu = 4 * k % n; //余数
	cout << "a=" << a << endl;
	cout << "yu=" << yu << endl;
	while (a > 0)
	{
		int temp = a % 10;
		result.insert(result.begin(), temp);//首部插入整数当前最后一位
		a /= 10;
	}
	int s = result.size();
	result.push_back(-1); //代表小数点
	while (yu != 0 && result.size() < precise + s + 1) //余数不为0且不满足精度要求
	{
		result.push_back(yu * 10 / n);
		yu = (yu * 10) % n;
	}
}

int main()
{
	vector<int> result;
	vector<int>::iterator it = result.begin();
	int precise = 1000;//precise代表小数点后几位小数
	pai(52345678, precise, result);
	cout << '\n' << "pi=";
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != -1)
			cout << result[i];
		else cout << ".";
	}
	result.clear();
	cout << endl;

	system("PAUSE");
	return 0;
}
