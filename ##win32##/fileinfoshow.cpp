#include<iostream>
#include<Windows.h>
using namespace std;
void Show_Time(SYSTEMTIME time);
int main() {
	HANDLE hFile, hr;
	hFile = CreateFile(
		TEXT("E:\\cmd\\C++ 程序设计语言：第4部分 标准库（原书第4版）.pdf"),
		0, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	CopyFile(
		TEXT("E:\\cmd\\C++ 程序设计语言：第4部分 标准库（原书第4版）.pdf"),
		TEXT("E:\\cmd\\C++ 程序设计语言.pdf"),
		1);
	//DeleteFile(TEXT("E:\\cmd\\C++ 程序设计语言.pdf"));
	double size = GetFileSize(hFile, NULL);
	cout << size / 1048576 << " MB" << endl;

	FILETIME create, last_r, last_m;
	GetFileTime(hFile, &create, &last_r, &last_m);
	SYSTEMTIME stUTC, stLocal1;
	FileTimeToSystemTime(&create, &stUTC);
	cout << "创建时间:     ";
	Show_Time(stUTC);

	FileTimeToSystemTime(&last_r, &stUTC);
	cout << "上次访问时间: ";
	Show_Time(stUTC);

	FileTimeToSystemTime(&last_m, &stUTC);
	cout << "上次修改时间: ";
	Show_Time(stUTC);
	CloseHandle(hFile);
}

void Show_Time(SYSTEMTIME time) {
	cout << time.wYear << " " << time.wMonth << " " << time.wDay << " ";
	cout << time.wHour << " " << time.wMinute << " " << time.wSecond << endl;
}