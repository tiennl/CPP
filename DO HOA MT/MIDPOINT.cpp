#include <graphics.h>
#include <conio.h>
#include <iostream>
void KhoiTaoDohoa() 
{ 
    int gd=0,gm=0; 
    initgraph(&gd,&gm,"d:\\tc\\bgi"); 
    setcolor(GREEN);
    cleardevice();
} 
void Ve8Diem(int x0, int y0, int x, int y, int color){
	putpixel(x0+x,y0+y,color);
	putpixel(x0-x,y0+y,color);
	putpixel(x0+x,y0-y,color);
	putpixel(x0-x,y0-y,color);
	putpixel(x0+y,y0+x,color);
	putpixel(x0-y,y0+x,color);
	putpixel(x0+y,y0-x,color);
	putpixel(x0-y,y0-x,color);
}
void Circle(int x0, int y0, int r){
   	int x=0;
   	int y=r;
   	int p=1-r;
   	while (x<=y){
   		Ve8Diem(x0,y0,x,y,15);
		if (p<0) p=p+2*x+3;	
		else{
			p=p+2*(x-y)+5;
			y--;
		}
		x++;
	}
	getch();
}
int main()
{
  	KhoiTaoDohoa();
	Circle(300,300,100);
}

