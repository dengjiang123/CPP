#include<iostream>
#include"mytime0.h"
int main() {
	Time plan(2, 30);
	Time code(2, 40);
	Time fix(5, 55);
	Time total;

	plan.Show();
	code.Show();
	fix.Show();
	total = code + fix + plan;
	total.Show();
	total = total - fix;
	total.Show();
	total = 3 * total;
	total.Show();
	std::cout << "Good! " << total << std::endl;

	return 0;

}