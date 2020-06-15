#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
void KhoiTaoDohoa() 
{ 
    int gd=0,gm=0; 
    initgraph(&gd,&gm,"d:\\tc\\bgi"); 
    setcolor(GREEN);
    cleardevice();
} 
void ve4diem(int xc, int yc, int x, int y, int color){
	putpixel(xc+x,yc+y,color);
	putpixel(xc-x,yc+y,color);
	putpixel(xc+x,yc-y,color);
	putpixel(xc-x,yc-y,color);
}
void ellipse(int xc, int yc, int a, int b, int color){
	float p,a2,b2,t;
	int x,y,x0,y0;
	a2=pow(a,2);
	b2=pow(b,2);
	t=sqrt(a2+b2);
	x0=a2/t;
	y0=b2/t;
	x=0;
	y=b;
	p=2*(b2/a2)-2*b+1;
	while (x<=x0 || y>=y0){
		ve4diem(xc,yc,x,y,color);
		if (p<0) p=p+2*(b2/a2)*(2*x+3);
		else{
			p=p-4*y+2*(b2/a2)*(2*x+3)+4;
			y--;
		}
		x++;
	}
	y=0;
	x=a;
	p=2*(a2/b2)-2*a+1;
	while (x>=x0 || y<=y0){
		ve4diem(xc,yc,x,y,color);
		if (p<0) p=p+2*(a2/b2)*(2*y+3);
		else{
			p=p-4*x+2*(a2/b2)*(2*y+3)+4;
			x--;
		}
		y++;
	}
	getch();
}
int main()
{
  	KhoiTaoDohoa();
	ellipse(50,50,50,25,GREEN);
}

