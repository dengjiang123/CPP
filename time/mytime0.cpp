#include<iostream>
#include"mytime0.h"

Time::Time() {
	hours = minutes = 0;
}

Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddHr(int h) {
	hours += h;
}

void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time& t) const {
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time& t) const {
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double n) const {
	Time result;
	int total = hours * 60 * n + minutes * n;
	result.minutes = total % 60;
	result.hours = total / 60;
	return result;
}

Time operator*(double n, const Time& t) {
	Time result;
	int total = t.hours * 60 * n + t.minutes * n;
	result.minutes = total % 60;
	result.hours = total / 60;
	return result;
}

void Time::Show() const {
	std::cout << hours << " hours, " << minutes << " minutes\n";
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours << " hours, " << t.minutes << " minutes\n";
	return os;
}