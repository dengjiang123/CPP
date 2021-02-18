//软件名称：数字雨
//文件名：main.cpp
//版本：2020_02_07
//软件说明：简单的数字雨效果，本例用绘图工具（绘图窗口）来实现数字雨效果
//作者：A贝尔（Abr）
//时间：2020年02月07日19：04分

#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

long int* fhckdx()//获取屏幕分辨率
{
	long int intstr[2] = { '\0' };
	intstr[0] = GetSystemMetrics(SM_CXSCREEN);
	intstr[1] = GetSystemMetrics(SM_CYSCREEN);
	return intstr;
}

int main()
{
	long int* intstrr = fhckdx();//获取屏幕分辨率
	int cx = intstrr[0];
	int cy = intstrr[1];

	char graph_id[61] = { 0 };
	// 设置随机函数种子
	srand((unsigned)time(NULL));

	initgraph(cx, cy);// 初始化图形模式 参数三可以有也可以没有 （NOCLOSE 禁用绘图环境的关闭按钮,NOMINIMIZE 禁用绘图环境的最小化按钮,SHOWCONSOLE 保留原控制台窗口。）

	HWND hwnd = GetHWnd();//获取当前窗口句柄
	MoveWindow(hwnd, 0, 0, cx, cy, FALSE);//设置窗口位置和新大小
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_CAPTION); //去标题栏
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & ~(WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME));  //去边框

	int  x = 0, y = 1;
	char c = 0;
	int sgnal = 16;
	settextstyle(16, 8, _T("Courier"));	// 设置字体
	// 设置颜色
	settextcolor(LIGHTGREEN);// 设置字体颜色  也可以用这种方式表示颜色==》RGB(00,255,00)（也就是绘图颜色跟（setcolor）一样）
	setlinecolor(RGB(255, 255, 255));// 设置绘图线颜色（黑色BLACK）(红色RAD)	（绿色GREEN）
	setbkcolor(BLACK);// 设置背景色为黑色
	cleardevice();// 用背景色清空屏幕	
	setcolor(LIGHTGREEN);// 设置绘图色为绿色
	setorigin(0, -16);//这个函数用于设置坐标原点。	
	setaspectratio(1, 1);
	for (int i1 = 0, a1 = 0; i1 <= cy, a1 <= 16; i1++, a1++)//（我电脑分辨率1366*768）不同分辨率机子效果有所差异，自己手动修改这里的数字参数来提升数字雨效果
	{
		for (int a = 0; a <= 60; a++)
		{
			outtextxy(a * (cx / 59), a1, graph_id[a]);
			clearrectangle(0, 0, cx, a1);//这个函数用于清空矩形区域。删除字符
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
		//if (_kbhit())break;//检测键盘是否被按下  是就直接退出循环
	}
	cleardevice();// 用背景色清空屏幕	
	// 关闭图形模式
	closegraph();
}
