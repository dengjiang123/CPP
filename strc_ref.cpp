#include <iostream>
#include <string>
//结构声明
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};
//函数原型：无返回值，含有一个自定义结构类型的引用常量作为参数
void display(const free_throws& ft);
//函数原型：无返回值，含有一个自定义结构类型的引用变量作为参数
void set_pc(free_throws& ft);
//函数原型：返回值是自定义结构类型的引用变量，含有两个参数，一个是引用常量作为参数
//一个是引用变量作为参数
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };
	//将引用作为返回值，在主函数中dup接收引用变量数据
	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	// use return value as argument
	//将函数的返回值作为参数
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	// use return value in assignment
	//将函数的返回值赋值给变量
	dup = accumulate(team, five);
	std::cout << "Displaying team:\n";
	display(team);
	std::cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
	// ill-advised assignment
	accumulate(dup, five) = four;
	std::cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	// std::cin.get();
	return 0;
}
//函数定义
void display(const free_throws& ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << "  Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}
void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}
//将引用作为返回值，需要与引用相对应的原始变量接收
free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
