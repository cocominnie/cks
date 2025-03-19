#include"welcome.h"

void welcome_text()
{
	int i;
	puthz(291, 203, "欢迎进入", 24, 24, DARKGRAY);
	puthz(248, 255, "家庭机器人看护系统", 24, 24, DARKGRAY);
	puthz(293, 306, "正在进入", 16, 16, DARKGRAY);
	for (i = 0; i < 3; i++)
	{
		puthz(300 + 20 * i, 330, "。", 16, 16, DARKGRAY);
		delay(800);
	}
}

void welcome_page()
{
	setbkcolor(LIGHTCYAN);
	setfillstyle(SOLID_FILL, LIGHTRED);
	bar(0, 240, 639, 479);
	setfillstyle(SOLID_FILL, GREEN);
	bar(118, 186, 554, 293);
	setfillstyle(SOLID_FILL, YELLOW);
	fillellipse(66, 60, 35, 35);//画太阳
	setfillstyle(SOLID_FILL, BROWN);
	fillellipse(235, 324, 30, 30);
	fillellipse(421, 324, 30, 30);
	welcome_text();
}