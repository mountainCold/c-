
#include "Logic.h"
#include "MapTank.h"
#include "Tank.h"
#include <fstream>
void WriteChar(int x, int y, int heath, WORD color)
{
	if (x < 0 || y < 0 || x>70 || y>50)
	{
		return;
	}
	COORD pos = { 2 * x,y };
	SetConsoleTextAttribute(g_hout, color);
	SetConsoleCursorPosition(g_hout, pos);
	printf("%d", heath);
	SetConsoleTextAttribute(g_hout, 7);
}
void WriteChar(int x, int y, const char* str, WORD color)
{
	if (x < 0 || y < 0 || x>70 || y>50)
	{
		return;
	}
	COORD pos = { 2 * x,y };
	SetConsoleTextAttribute(g_hout, color);
	SetConsoleCursorPosition(g_hout, pos);
	printf(str);
	SetConsoleTextAttribute(g_hout, 7);
}
void ShowCuror()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hout, &cci);
}
void WriteTank(int x, int y, int color)
{
	WriteChar(x - 1, y - 1, "  ", color);
	WriteChar(x + 1, y - 1, "  ", color);
	WriteChar(x, y - 1, "◆", color);
	WriteChar(x, y, "⊙");
	WriteChar(x - 1, y, "■", color);
	WriteChar(x + 1, y, "■", color);
	WriteChar(x - 1, y + 1, "■", color);
	WriteChar(x + 1, y + 1, "■", color);
	WriteChar(x, y + 1, "  ", color);
}
void DwFrame(int x1, int x2, int y1, int y2, int n)
{

	for (int j = y1; j < y2; j++)
	{
		WriteChar(x1, j, "□", n % 7 + 2);
	}
	for (int jj = y1; jj <= y2; jj++)
	{
		WriteChar(x2, jj, "□", n % 7 + 2);
	}

	for (int ii = x1; ii < x2; ii++)
	{
		WriteChar(ii, y1, "□", n % 7 + 2 | 3);
	}
	for (int i = x1; i < x2; i++)
	{
		WriteChar(i, y2, "□", n % 7 + 2 | 5);
	}
}
int WriteFood(int x, int y)
{

	if (Map.GetMapVal(x, y) == 0)
	{
		WriteChar(x, y, "★", 9);
		Map.SetMap(x, y, 9);
		return 1;
	}
	return 0;
}
int MessageListener(int x)
{

	INPUT_RECORD ir = { 0 };
	DWORD dwCount = 0;
	DWORD dwt = 0;
	bool stat = true;
	HANDLE g_hint = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(g_hint, &dwt);
	SetConsoleMode(g_hint, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | dwt);

	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	while (stat)
	{
		ReadConsoleInput(
			g_hint,  //输出句柄，固定写法  传入参数
			&ir,     //用于获取在控制台上的信息   传出参数
			1,       //ir 的个数            传入参数
			&dwCount //传出的，读取了多少个信息

		);
		if (ir.EventType == MOUSE_EVENT)
		{

			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (MousePos.X > 1 && MousePos.X < 118 && MousePos.Y>0 && MousePos.Y < 49)
				{
					if (x == 0)
					{
						PlaySound(L"sound\\鼠标点击.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
				}
				MousePos = ir.Event.MouseEvent.dwMousePosition;
				stat = false;
				
			}
			if (ir.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{


			}
			/*return 0;*/
		}
		else if (ir.EventType == KEY_EVENT)
		{
			return KeyListener();
		}
		/*return 0;*/
	}
	return 0;
}
void KeyListener(char& ch1, char& ch2, char& bch1, char& bch2)
{
	if (KEYDOWN(27))
	{
		g_Game = false;
		gLevel = 1;

	}
	if (KEYDOWN(13))
	{
		if (t4.heart > 1 && t5.heart == 0)
		{
			t4.heart--;
			t5.heart++;
		}
		if (t5.heart > 1 && t4.heart == 0)
		{
			t5.heart--;
			t4.heart++;
		}
	}
	if (KEYDOWN(87) != 0)
	{
		ch1 = 'w';
	}
	else if (KEYDOWN(83))
	{
		ch1 = 's';
	}
	else if (KEYDOWN(32))
	{
		while (KEYDOWN(32));
		ch1 = 32; 
		printf("a");
		static int i = 0;
		++i;
	}
	else if (KEYDOWN(65))
	{
		ch1 = 'a';
	}
	else if (KEYDOWN(68))
	{
		ch1 = 'd';
	}
	else {
		ch1 = 0;
	}
	if (KEYDOWN(101))
	{
		ch2 = 'w';
	}
	else if (KEYDOWN(98))
	{
		ch2 = 's';
	}
	else if (KEYDOWN(97))
	{
		ch2 = 'a';
	}
	else if (KEYDOWN(99))
	{
		ch2 = 'd';
	}
	else
	{
		ch2 = 0;
	}
	if (KEYDOWN(74))
	{
		bch1 = 'j';
	}
	else
	{
		bch1 = 0;
	}
	if (KEYDOWN(100))
	{
		bch2 = 'j';
	}
	else
	{
		bch2 = 0;
	}

}
int KeyListener()
{
	if (KEYDOWN(27)) //27 Escape 键
	{
		return 27;
	}
	else if (KEYDOWN(13)) //13 Enter 键
	{
		return 13;
	}
	else if (KEYDOWN(32)) //32 Space 键
	{
		return 32;
	}
	else if (KEYDOWN(97))
	{
		return 1;
	}
	else if (KEYDOWN(98))
	{
		return 2;
	}
	else if (KEYDOWN(99))
	{
		return 3;
	}
	else if (KEYDOWN(100))
	{
		return 4;
	}
	else if (KEYDOWN(101))
	{
		return 5;
	}
	else if (KEYDOWN(102))
	{
		return 6;
	}
	else if (KEYDOWN(103))
	{
		return 7;
	}
	else if (KEYDOWN(104))
	{
		return 8;
	}
	else if (KEYDOWN(105))
	{
		return 9;
	}
	return 0;
}
