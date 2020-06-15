#include <graphics.h>
#include <conio.h>
#include <iostream>
void KhoiTaoDohoa() 
{ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
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
   	int p=3-2*r;
   	while (x<=y){
   		Ve8Diem(x0,y0,x,y,15);
		if (p<0) p=p+4*x+6;	
		else{
			p=p+4*(x-y)+10;
			y--;
		}
		x++;
	}
	getch();
}
int main()
{
  	KhoiTaoDohoa();
	Circle(100,100,100);
}

