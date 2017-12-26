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
int Num;   //���
TCHAR Line[400];  //��·
TCHAR Name[20];//��������
TCHAR infor[200];//��������
int   TravelTime;//·��ʱ��
int   Eatingtime;//�ò�ʱ��
TCHAR  Kind[20];//����
int  Aveprice;//ƽ����λ
TCHAR Place[50];//����
}Restaurant;

typedef struct{
int month;   //�ò��·�
int day;  //�ò�����
TCHAR Name[20];//��������
TCHAR Kind[20];   //��������
int Aveprice;//����ƽ����λ
int Price;//����ʵ������
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
	loadimage(NULL, _T("D:\\��ʳ��������ͼ1.jpg"),640,480);
	setfillcolor(LIGHTBLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30,0.4, _T("����"));
	
	/*¼������������Ϣ*/
	for(i=0;i<100;i++)
		test[i]=res[i];
	initfood();
}

void initfood(void)               //�����ʼ��
{
	int flag=1;
	setbuf(stdin,NULL);
    loadimage(NULL, _T("D:\\��ʳ��������ͼ1.jpg"),640,480);
	setfillcolor(LIGHTBLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 10);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30,0.4, _T("����"));
	fillrectangle(440,0,640,96);
	fillrectangle(440,96,640,192);
	fillrectangle(440,192,640,288);
	fillrectangle(440,288,640,384);
	fillrectangle(440,384,640,480);
	fillrectangle(0,420,100,480);
	outtextxy(480,48,_T("��������"));
	outtextxy(480,144,_T("������λ"));
	outtextxy(480,240,_T("��������"));
	outtextxy(480,336,_T("��Уʱ��"));
	outtextxy(480,432,_T("��ѯ"));
	outtextxy(20,432,_T("����"));

	while(flag)
	{
		if (MouseHit())   //���
	    {
			m1=GetMouseMsg();//��ȡ���״̬
			
			if(m1.uMsg==WM_MOUSEMOVE)
			{
				 if(m1.x<=640&&m1.x>=440&&m1.y>=0&&m1.y<=96)
				     outtextxy(100,100,_T("���ǵĲ�����"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>96&&m1.y<=192)
					 outtextxy(100,100,_T("����Ҫ����һ����������\n�ļ�λ����ż"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>192&&m1.y<288)
					 outtextxy(100,100,_T("���ǵĲ�����Ҫ�ֲ�����\n�µ���"));
				else if(m1.x<=640&&m1.x>=440&&m1.y>288&&m1.y<=384)
				     outtextxy(100,100,_T("��Ҫע��һ�����ķ�Уʱ\n��Ŷ"));
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
	settextstyle(30,0.4, _T("����"));
	outtextxy(480,48,_T("��������"));
	outtextxy(480,144,_T("������λ"));
	outtextxy(480,240,_T("��������"));
	outtextxy(480,336,_T("��Уʱ��"));
	outtextxy(480,432,_T("��ѯ"));
	outtextxy(60,620,_T("����"));
	FlushMouseMsgBuffer();
	while(true)
	{
		if (MouseHit())   //���
	    {
			m1=GetMouseMsg();//��ȡ���״̬
			
			if(m1.uMsg==WM_LBUTTONDOWN)
			{
				 if(m1.x>=40&&m1.x<=140&&m1.y>=420&&m1.y<=480)//���ص�������
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
	InputBox(s1,10,_T("����������ԵĲ���"),_T("��ʳ����"),false);// �����ַ������������������û�����
	if((*s1)!=0)//�û��Ƿ���ȥ�˲�ɸѡ�İ��
	{
	int i,j=0;char s[10];
	for(i=0;i<100;i++)//�ڲ����ϵ�ɸѡ����
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
	InputBox(ad,10,_T("��������Ԥ�ڵ���������"),_T("��ʳ����"),false);
	InputBox(au,10,_T("��������Ԥ�ڵ���������"),_T("��ʳ����"),false);
    if((*ad)!=0)
	{
		if(ad[2]!='\0')//���û�������ַ���ת��Ϊ���Ӧ������
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
		pu=1000000;//��ȡ�����޵�Ч��һ��
    int i,j=0;
	for(i=0;i<100;i++)//�ڼ�λ�ϵ�ɸѡ����
		if(test[i].Aveprice>=pd&&test[i].Aveprice<=pu)
			{
				test[j]=res[i];
		     j++;
		}
	initfood();
}

void placescreen(void)
{
	InputBox(s2,10,_T("�����������������ĵ���"),_T("��ʳ����"),false);
	int i,j=0;char s[10];
	if(*(s2)!=0)
	{
	for(i=0;i<100;i++)//���ò͵ص��ϵ�ɸѡ����
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
	InputBox(hour,10,_T("��������Ԥ�ڷ�У��Сʱ"),_T("��ʳ����"),false);
	InputBox(min,10,_T("��������Ԥ�ڷ�У�ķ���"),_T("��ʳ����"),false);
	 if(min[2]!='\0')//���û�������ַ���ת��Ϊ���Ӧ������
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
   InputBox(save,10,_T("���������Ƿ�Ը��洢�˴��ò�����"),_T("��ʳ����"),false);
}

void present(void)
{
   
}
