#include<iostream>
#include<cstdlib>
#include<graphics.h>
#include<conio.h>
#include<ctime>
using namespace std;
int main() {
	int cx, cy;
	char graph_id[61] = { 0 };
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);
	srand(time(0));
	initgraph(cx, cy);
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 0, 0, cx / 2, cy / 2, FALSE);
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_CAPTION);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & ~(WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME));
	settextstyle(16, 8, _T("Courier"));
	settextcolor(LIGHTGREEN);
	setlinecolor(RGB(255, 255, 255));
	setbkcolor(BLACK);
	cleardevice();
	setcolor(LIGHTGREEN);
	setorigin(0, -16);

	int  x = 0, y = 1;
	char c = 0;
	int sgnal = 16;
	setaspectratio(1, 1);
	for (int i1 = 0, a1 = 0; i1 <= cy, a1 <= 16; i1++, a1++) {
		for (int a = 0; a <= 60; a++) {
			outtextxy(a * (cx / 59), a1, graph_id[a]);
			clearrectangle(0, 0, cx, a1);
		}
		if (sgnal == 16)
		{
			for (int a = 0; a <= 60; a++)
			{
				graph_id[a] = ' ';
			}
			clearrectangle(0, 0, cx, 16);//这个函数用于清空矩形区域。删除字符
			for (int i = 0; i <= 30; i++)
			{
				x = (rand() % 60) * 32;
				c = (rand() % 26) + 65;
				graph_id[x / 32] = c;
				outtextxy(x, 0, c);
				sgnal = 0;
			}
		}
		sgnal++;
		IMAGE img;
		getimage(&img, 0, 0, cx, cy);
		putimage(0, 1, &img);
		//		Sleep(1);
		if (a1 >= 16)a1 = 0;
		if (i1 >= cy)i1 = 0;
	}
	cleardevice();
	closegraph();
	return 0;
}