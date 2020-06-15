#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define LEFT 1
#define RIGHT 2
#define BELOW 4
#define ABOVE 8
#define TRUE 1
#define FALSE 0
#define Step 10;
using namespace std;
int X0,Y0;
struct toado2D
{
	int x,y;
};
toado2D tren,duoi,a,b;
void nhap()
{
	tren.x=150; tren.y=100;
	duoi.x=400; duoi.y=300;
	a.x=10;
	a.y=550;
	b.x=550;
	b.y=10;
}
void vehinh()
{
	rectangle(tren.x,tren.y,duoi.x,duoi.y);
	setwritemode(XOR_PUT);
	line(a.x,a.y,b.x,b.y);
	getch();
	line(a.x,a.y,b.x,b.y);
}
int ma(toado2D p)
{
	int s=0;
	if(p.x<tren.x) s=s | LEFT;
	if(p.x>duoi.x) s=s | RIGHT;
	if(p.y>duoi.y) s=s | BELOW;
	if(p.y<tren.y) s=s | ABOVE;
	return s;
}
int round(float x)
{
	if(x>0) return int (x+0.5);
	else return int (x-0.5);
}
void swap(toado2D &a, toado2D &b)
{
	toado2D t=a; a=b; b=t;
}
void clip(toado2D a, toado2D b, toado2D tren, toado2D duoi)
{
	int stop=FALSE, draw=FALSE;
	while (stop!=TRUE)
	{
		if((ma(a)==0)&&(ma(b)==0))
		{
			stop=TRUE; draw=TRUE;
		}
		else  if ((ma(a)&ma(b))!=0) stop=TRUE;
	else
	{
		if(((ma(a)&ma(b))==0)&&((ma(a)!=0)||(ma(b)!=0)))
		{
			if(ma(a)==0) swap(a,b);
			float m=float(b.y-a.y)/(b.x-a.x);
			if((ma(a) & LEFT)!=0)
			{
				a.y=a.y+round(m*(tren.x-a.x));
				a.x=tren.x;
			}
			else if((ma(a)& RIGHT)!=0)
			{
				a.y=a.y+round(m*(duoi.x-a.x));
				a.x=duoi.x;
			}
			else if((ma(a)&ABOVE)!=0)
			{
				a.x=a.x+round(float(tren.y-a.y)/m);
				a.y=tren.y;
			}
			else if((ma(a)&BELOW)!=0)
			{
				a.x=a.x+round(float(duoi.y-a.y)/m);
				a.y=duoi.y;
			}
		}
		}
	}
	if(draw) line(a.x,a.y,b.x,b.y);
	}
void hienten()
{
	settextstyle(0,0,3);
	outtextxy(10,50,"huy");
}
void vehinh(int X0, int Y0)
{
	setcolor(12);
	line(X0+100,Y0+10,X0+10,Y0+100);
	line(X0+10,Y0+10,X0+10,Y0+100);
	line(X0+10,Y0+10,X0+100,Y0+10);	
}
void chay()
{
	char ch;
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	setwritemode(XOR_PUT);
	vehinh(X0,Y0);
	do
	{
		ch=getch();
		switch(ch)
		{
			case 75 :
				vehinh(X0,Y0);
				X0 -= Step;
				cleardevice();
				vehinh(X0,Y0);
				break;
			case 77 :
				vehinh(X0,Y0);
				X0 += Step;
				cleardevice();
				vehinh(X0,Y0);
				break;
			case 72 :
				vehinh(X0,Y0);
				Y0 -= Step;
				cleardevice();
				vehinh(X0,Y0);
				break;
			case 80 :
				vehinh(X0,Y0);
				Y0 += Step;
				cleardevice();
				vehinh(X0,Y0);
				break;
		}
	}
	while(ch!=27);
}
int main()
{
	nhap();
	int driver= DETECT,mode;
	initgraph(&driver,&mode,"");
	cleardevice();
	vehinh();
	clip(a,b,tren,duoi);
	floodfill(350,250,15);
	getch();
	hienten();
	getch();
	cleardevice();
	cleardevice();
	chay();
	getch();
}

