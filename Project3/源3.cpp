#include<windows.h>
using namespace std;
void HideWindow() {
	HWND hwnd;
	hwnd = FindWindow(TEXT("ConsoleWindowClass"), NULL);
	if (hwnd) ShowWindow(hwnd, SW_HIDE);
	return;
}
int main() {
	HideWindow();
	int pix;
	HWND wnd;
	HDC dc;
	wnd = FindWindow(TEXT("SysListView32"), NULL);
	dc = GetDC(wnd);
	pix = RGB(0, 0, 0);
	int x = 0;
	int y = 0;
	while (1)
		for (int i = 0; i < 5000; i++) {
			for (int j = 0; j < 1000; j++) {
				SetCursorPos(0, 0);
				pix = RGB(i % 255, j % 255, (i + j) % 255);
				SetPixel(dc, x + i, y + j, pix);
			}
		}
	return 0;
}
