#include"homemap.h"

void map_picture()
{
	cleardevice();
	setbkcolor(WHITE);
	line2(143, 143, 143, 378);
	line2(143, 143, 263, 143);
	line2(263, 143, 263, 168);
	line2(263, 214, 263, 233);
	line2(263, 233, 263, 290);
	line2(263, 326, 263, 378);
	line2(143, 378, 263, 378);
	line2(263, 143, 483, 143);
	line2(263, 233, 292, 233);
	line2(330, 233, 401, 233);
	line2(451, 233, 483, 233);
	line2(483, 143, 483, 233);
	line2(369, 233, 369, 290);
	line2(369, 327, 369, 378);
	line2(263, 378, 369, 378);
	line2(369, 378, 483, 378);
	line2(483, 233, 483, 378);
	bar1(288, 420, 352, 455, LIGHTRED);
	puthz(290, 425, "退出", 24, 30, DARKGRAY);
	puthz(240, 86, "家庭平面图", 32, 32, DARKGRAY);
	puthz(185, 226, "厨房", 16, 16, DARKGRAY);
	puthz(315, 180, "客厅", 16, 16, DARKGRAY);
	puthz(288, 262, "洗漱室", 16, 16, DARKGRAY);
	puthz(414, 262, "卧室", 16, 16, DARKGRAY);
}

void homemap(int* func)
{
	int tmp = *func;
	clrmous(MouseX, MouseY);
	map_picture();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(288, 420, 352, 455) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(288, 420, 352, 455) == 1)
		{
			clrmous(MouseX, MouseY);
			*func = tmp;
			break;
		}
		else
		{
			MouseS = 0;
		}
	}
}
