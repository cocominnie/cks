#include <allfunc.h>

void register_picture()
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	bar1(63, 67, 572, 124, LIGHTRED);
	bar1(63, 151, 572, 414, YELLOW);
	bar1(101, 174, 174, 220, WHITE);
	bar1(101, 254, 174, 300, WHITE);
	bar1(201, 174, 532, 220,WHITE);
	bar1(201, 254, 532, 300, WHITE);
	bar1(139, 322, 268, 363, LIGHTCYAN);
	bar1(346, 322, 471, 363, LIGHTCYAN);
	line1(210, 206, 520, 206);
	line1(210, 290, 520, 290);
	/*line1(146, 402, 260, 402);
	line1(350, 402, 472, 402);*/
	puthz(173, 71, "注册系统", 48, 80, DARKGRAY);
	puthz(113, 185, "账号", 24, 24, DARKGRAY);
	puthz(113, 265, "密码", 24, 24, DARKGRAY);
	puthz(164, 326, "确认", 32, 40, DARKGRAY);
	puthz(368, 326, "返回", 32, 40, DARKGRAY);
}

//新用户注册
void rigister_login(int *func)
{
	struct USER temp={0};//存储信息的用户结构体 
	char judge[10]="\0";//用于判断的密码 

    clrmous(MouseX,MouseY);
	register_picture();

    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
        
		if (mouse_press(201, 174, 532, 220) == 2)
		{
			MouseS = 2;
		}
        else if(mouse_press(201, 174, 532, 220)==1)   //输入账号
		{
			clrmous(MouseX,MouseY);
			bar1(201, 174, 532, 220,WHITE);
			strcpy(temp.name,"\0");
			Getinfo(205,190,temp.name, 10, 201, 174, 532, 220);
			 
		}
		else if (mouse_press(201, 254, 532, 300) == 2)
		{
			MouseS = 2;
		}
		else if(mouse_press(201, 254, 532, 300)==1)    //输入密码
		{
			clrmous(MouseX,MouseY);
			bar1(201, 254, 532, 300,WHITE);
			strcpy(temp.code,"\0");
			Getcode(205,269,temp.code,10, 201, 254, 532, 300);	 
		}
		else if (mouse_press(139, 322, 268, 363) == 2)
		{
			MouseS = 1;
		}
		else if(mouse_press(139, 322, 268, 363)==1)     //点击确认键
		{
			delay(200);
			if(strcmp(temp.name,"\0")!=0)//用户名不为空 
			{
				if(strcmp(temp.code,"\0")!=0)//密码不为空 
				{
				      if(save_user(temp)==0)
                      {
						  puthz(250, 225, "注册成功！", 24,24,DARKGRAY);
                        *func=1;
				        break;
                      }
                      else
                      {
                        puthz(250,225,"用户名已被注册！", 24, 24, DARKGRAY);
                        delay(1500);
						bar1(224, 224, 516, 253,YELLOW);
                      }
				}
				else
				{
					puthz(250, 225,"密码为空！", 24, 24, DARKGRAY);
				    delay(1500);
				    bar1(224, 224, 516, 253,YELLOW);
				}	
			}
			else
			{
				puthz(250, 225,"用户名为空！", 24, 24, DARKGRAY);
				delay(1500);
				bar1(224, 224, 516, 253,YELLOW);
			}	
		}
		else if (mouse_press(346, 322, 471, 363) == 2)
		{
			MouseS = 1;
		}
		else if(mouse_press(346, 322, 471, 363)==1)
		{
			delay(200);
			*func=1;
			break;
		}
		else
		{
			MouseS = 0;
		}
    }
}

void login_picture()
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	bar1(63, 67, 572, 124, LIGHTRED);
	bar1(63, 151, 572, 414, YELLOW);
	bar1(101, 174, 174, 220, WHITE);
	bar1(101, 254, 174, 300, WHITE);
	bar1(201, 174, 532, 220, WHITE);//账号栏
	bar1(201, 254, 532, 300, WHITE);//密码栏
	bar1(139, 322, 268, 363, LIGHTCYAN);//按钮1
	bar1(346, 322, 471, 363, LIGHTCYAN);//按钮2
	line1(210, 206, 520, 206);
	line1(210, 290, 520, 290);
	line1(146, 402, 260, 402);
	line1(350, 402, 472, 402);
	puthz(173, 71, "登录系统", 48, 80, DARKGRAY);
	puthz(113, 185, "账号", 24, 24, DARKGRAY);
	puthz(113, 265, "密码", 24, 24, DARKGRAY);
	puthz(164, 326, "登录", 32, 40, DARKGRAY);
	puthz(368, 326, "注册", 32, 40, DARKGRAY);
	puthz(155, 370, "用法简介", 24, 24, BLUE);
	puthz(357, 370, "退出程序", 24, 24, BLUE);
}

//用户使用账号登录
void user_login(int *func,int *unum)
{
    char name[10]="\0";
	char code[10]="\0";
    int i=-5;

    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);

    clrmous(MouseX,MouseY);
	login_picture();

    while(1)
    {
        newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(201, 174, 532, 220) == 2)
		{
			MouseS = 2;
		}
        else if(mouse_press(201, 174, 532, 220)==1)//点击账号框 
		{
			clrmous(MouseX,MouseY);
			strcpy(name,"\0");
			bar1(201, 174, 532, 220,WHITE);
			Getinfo(205,190,name,10, 201, 174, 532, 220);//得到账号 
		}
		else if (mouse_press(201, 254, 532, 300) == 2)
		{
			MouseS = 2;
		}
        else if(mouse_press(201, 254, 532, 300)==1)//点击密码框 
		{
			clrmous(MouseX,MouseY);
			strcpy(code,"\0");
			bar1(201, 254, 532, 300,WHITE);
			Getcode(205,269,code,10, 201, 254, 532, 300);//得到密码 
		}
		else if (mouse_press(139, 322, 268, 363) == 2)
		{
			MouseS = 1;
		}
        else if(mouse_press(139, 322, 268, 363)==1)//点击登录
        {
			delay(200);
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				*unum=i;
				DestroyUList(&UL);
				*func=3;      //进入主界面
                break;
			}
			if(i==-2)//密码输入错误 
			{
				puthz(250,225,"密码错误！", 24, 24, DARKGRAY);
			    delay(1500);
				bar1(224, 224, 516, 253,YELLOW);
			}
			if(i==-3)//用户不存在 
			{
				puthz(250, 225,"用户不存在！", 24, 24, DARKGRAY);
			    delay(1500);
				bar1(224, 224, 516, 253,YELLOW);
			} 
        }
		else if (mouse_press(346, 322, 471, 363) == 2)
		{
			MouseS = 1;
		}
        else if(mouse_press(346, 322, 471, 363)==1)
        {
			delay(200);
			*func = 2;
            break;
        }
		else if (mouse_press(155, 370, 251, 394) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(155, 370, 251, 394) == 1)
		{
			*func = -1;
			break;
		}
		else if (mouse_press(357, 370, 453, 394) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(357, 370, 453, 394) == 1)
		{
			clrmous(MouseX, MouseY);
			closegraph();
			break;
		}
		else
		{
			MouseS = 0;
		}
    }
}









