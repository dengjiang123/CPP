#include<iostream>
#include<Windows.h>
#include<atltime.h>
#include<ctime>
using namespace std;

void Show_Time(SYSTEMTIME time);
void Show_Remain(SYSTEMTIME start, SYSTEMTIME end);

int main() {
	SYSTEMTIME sys, end;
	GetLocalTime(&sys);

	end.wYear = 2020;
	end.wMonth = 12;
	end.wDay = 26;
	end.wHour = 8;
	end.wMinute = 30;

	Show_Time(sys);
	Show_Remain(sys, end);
	system("pause");
}

void Show_Time(SYSTEMTIME time) {
	cout << time.wYear << " " << time.wMonth << " " << time.wDay << " ";
	cout << time.wHour << " " << time.wMinute << " " << time.wSecond << endl;
}

void Show_Remain(SYSTEMTIME start, SYSTEMTIME end) {
	CTime left(start);
	CTime right(end);

	int day, hours, minutes, seconds;
	CTimeSpan span = right - left;
	day = span.GetDays();
	hours = span.GetHours();
	minutes = span.GetMinutes();
	seconds = span.GetSeconds();
	cout << day << " " << hours << " " << minutes << " " << seconds << endl;
}