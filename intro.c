#include"intro.h"

void intro_picture()
{
	cleardevice();
	setbkcolor(GREEN);
	puthz(210, 176, "欢迎使用本操作系统", 32, 32, DARKGRAY);
	outtextxy(270, 220, "A");
	puthz(296, 220, "往左移动", 24, 24, DARKGRAY);
	outtextxy(270, 250, "B");
	puthz(296, 250, "往右移动", 24, 24, DARKGRAY);
	bar1(286, 398, 354, 434, LIGHTCYAN);
	puthz(288, 400, "返回", 32, 32, DARKGRAY);
}

void intro_page(int* func)
{
	clrmous(MouseX, MouseY);
	intro_picture();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(286, 398, 354, 434) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(286, 398, 354, 434) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(200);
			*func = 1;
			break;
		}
		else
		{
			MouseS = 0;
		}
	}
}