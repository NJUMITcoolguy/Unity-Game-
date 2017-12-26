#include<time.h>
#include<string.h>
#include"stdafx.h"
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<tchar.h>

MOUSEMSG m1;

typedef struct{
	int hour;
	int min;
	int sec;
}mTime;

typedef struct{
int Num;   //编号
TCHAR Line[400];  //线路
TCHAR Name[20];//餐厅名称
TCHAR infor[200];//基本介绍
int   TravelTime;//路程时间
int   Eatingtime;//用餐时间
TCHAR  Kind[20];//餐种
int  Aveprice;//平均价位
TCHAR Place[50];//地区
}Restaurant;

typedef struct{
int month;   //用餐月份
int day;  //用餐日期
TCHAR Name[20];//餐厅名称
TCHAR Kind[20];   //餐厅种类
int Aveprice;//餐厅平均价位
int Price;//餐厅实际消费
}Record;

Record a[1000];
Restaurant res[100];
Restaurant test[100];
TCHAR s1[20]={0};
TCHAR s2[20]={0};
TCHAR ad[10]={0},au[10]={0};
TCHAR hour[10]={0},min[10]={0};
TCHAR b[10]={0};
int pd=0,pu=0;
int h=0,m=0;
TCHAR save[10];

void initfood(void);
int FoodMenu(void);
extern void init(void);
void Searchresult(void);
void kindscreen(void);
void pricescreen(void);
void placescreen(void);
void savetime(void);
void present(void);

void Food(void)
{
	int i;
	loadimage(NULL, _T("D:\\美食导航背景图1.jpg"),640,480);
	setfillcolor(LIGHTBLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30,0.4, _T("楷体"));
	
	/*录入餐厅的相关信息*/
	for(i=0;i<100;i++)
		test[i]=res[i];
	initfood();
}

void initfood(void)               //界面初始化
{
	int flag=1;
	setbuf(stdin,NULL);
    loadimage(NULL, _T("D:\\美食导航背景图1.jpg"),640,480);
	setfillcolor(LIGHTBLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30,0.4, _T("楷体"));
	fillrectangle(440,0,640,96);
	fillrectangle(440,96,640,192);
	fillrectangle(440,192,640,288);
	fillrectangle(440,288,640,384);
	fillrectangle(440,384,640,480);
	fillrectangle(0,420,100,480);
	outtextxy(480,48,_T("餐厅种类"));
	outtextxy(480,144,_T("餐厅价位"));
	outtextxy(480,240,_T("餐厅地区"));
	outtextxy(480,336,_T("回校时间"));
	outtextxy(480,432,_T("查询"));
	outtextxy(20,432,_T("返回"));

	while(flag)
	{
		if (MouseHit())   //检测
	    {
			m1=GetMouseMsg();//获取鼠标状态
			
			if(m1.uMsg==WM_MOUSEMOVE)
			{
				 if(m1.x<=640&&m1.x>=440&&m1.y>=0&&m1.y<=96)
				     outtextxy(100,100,_T("我们的餐种有"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>96&&m1.y<=192)
					 outtextxy(100,100,_T("您需要考虑一下您所期望\n的价位区间偶"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>192&&m1.y<288)
					 outtextxy(100,100,_T("我们的餐厅主要分布在以\n下地区"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>288&&m1.y<=384)
				     outtextxy(100,100,_T("您要注意一下您的返校时\n间哦"));
			}
		}
		FlushMouseMsgBuffer();
		if(m1.uMsg==WM_LBUTTONDOWN)
			flag=0;
	}

	switch(FoodMenu())
	{
	case 1:Sleep(200);kindscreen();break;
	case 2:Sleep(200);pricescreen();break;
	case 3:Sleep(200);placescreen();break;
	case 4:Sleep(200);savetime();break;
	case 5:Sleep(200);Searchresult();break;
    case 6:Sleep(200);init();break;

	}
}

int FoodMenu(void)        
{
	int y1=40,i=0;
	char c;
	setfillcolor(LIGHTBLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30,0.4, _T("楷体"));
	outtextxy(480,48,_T("餐厅种类"));
	outtextxy(480,144,_T("餐厅价位"));
	outtextxy(480,240,_T("餐厅地区"));
	outtextxy(480,336,_T("回校时间"));
	outtextxy(480,432,_T("查询"));
	outtextxy(60,620,_T("返回"));
	FlushMouseMsgBuffer();
	while(true)
	{
		if (MouseHit())   //检测
	    {
			m1=GetMouseMsg();//获取鼠标状态
			
			if(m1.uMsg==WM_LBUTTONDOWN)
			{
				 if(m1.x>=40&&m1.x<=140&&m1.y>=420&&m1.y<=480)//返回到主界面
					 return 6;
				else if(m1.x<=640&&m1.x>=440&&m1.y>=0&&m1.y<=96)
				     return 1; 
				else if(m1.x<=640&&m1.x>=440&&m1.y>96&&m1.y<=192)
					 return 2;
				else if(m1.x<=640&&m1.x>=440&&m1.y>192&&m1.y<288)
					 return 3;
				else if(m1.x<=640&&m1.x>=440&&m1.y>288&&m1.y<=384)
				     return 4;
				else if(m1.x<=640&&m1.x>=440&&m1.y>384&&m1.y<=480)
				     return 5;

		}
		if (_kbhit())
	    {
            c=_getch();
			if(c>='1'&&c<='6')
				return (c-'0');
         }
	}
}
}

void kindscreen(void)
{
	InputBox(s1,10,_T("请输入您想吃的餐种"),_T("美食导航"),false);// 定义字符串缓冲区，并接收用户输入
	if((*s1)!=0)//用户是否略去此步筛选的半段
	{
	int i,j=0;char s[10];
	for(i=0;i<100;i++)//在餐种上的筛选过程
		if(!(_tcscmp(test[i].Kind,s1)))
			{
				test[j]=res[i];
		     j++;
	   }
	}
	initfood();
}

void pricescreen(void)
{
	InputBox(ad,10,_T("请输入您预期的消费下限"),_T("美食导航"),false);
	InputBox(au,10,_T("请输入您预期的消费上限"),_T("美食导航"),false);
    if((*ad)!=0)
	{
		if(ad[2]!='\0')//将用户输入的字符串转化为相对应的数字
		pd=100*ad[0]+10*ad[1]+ad[2];
	else if(ad[2]=='\0'&&ad[1]!='\0')
		pd=10*ad[0]+ad[1];
	else if(ad[1]=='\0')
		pd=ad[0];
	}
	if((*au)!=0)
	{
	  if(au[2]!='\0')
		pu=100*au[0]+10*au[1]+au[2];
	else if(au[2]=='\0'&&ad[1]!='\0')
		pu=10*au[0]+au[1];
	else if(au[1]=='\0')
		pu=au[0];
	}
	else
		pu=1000000;//与取消上限的效果一样
    int i,j=0;
	for(i=0;i<100;i++)//在价位上的筛选过程
		if(test[i].Aveprice>=pd&&test[i].Aveprice<=pu)
			{
				test[j]=res[i];
		     j++;
		}
	initfood();
}

void placescreen(void)
{
	InputBox(s2,10,_T("请输入您期望餐厅的地区"),_T("美食导航"),false);
	int i,j=0;char s[10];
	if(*(s2)!=0)
	{
	for(i=0;i<100;i++)//在用餐地点上的筛选过程
		if(!(_tcscmp(test[i].Place,s2)))
			{
				test[j]=res[i];
		     j++;
	     }
	}
		initfood();
}

void savetime(void)
{
	InputBox(hour,10,_T("请输入您预期返校的小时"),_T("美食导航"),false);
	InputBox(min,10,_T("请输入您预期返校的分钟"),_T("美食导航"),false);
	 if(min[2]!='\0')//将用户输入的字符串转化为相对应的数字
		m=100*min[0]+10*min[1]+min[2];
	else if(min[2]=='\0'&&min[1]!='\0')
		m=10*min[0]+min[1];
	else if(min[1]=='\0')
		m=min[0];
     if(hour[1]!='\0')
		h=10*hour[0]+hour[1];
	else if(hour[1]=='\0')
		h=hour[0];
	initfood();
}

void Searchresult(void)
{
   present();
   InputBox(save,10,_T("请输入您是否愿意存储此次用餐数据"),_T("美食导航"),false);
}

void present(void)
{
   
}
