#include<conio.h>
#include<graphics.h>
float a,b,c,d,e,min,max;
int round(float x){
	if(x>0) return int (x+0.5);
	else    return int (x-0.5);
}
void khoitaodohoa(){
	int gd=0, gm=0;
	initgraph(&gd,&gm,"");
}
float f(float x){
	return (a*x*x+b*x+c)/(d*x+e);
}
void vedothi(float min,float max){
	int x0,y0,x1,y1,x2,y2;
	float x,dx,k;
	x0=getmaxx()/2;
	y0=getmaxy()/2;
	k=(float)getmaxx()/30;
	dx=0.001;
	setcolor(15);
	line(0,y0,2*x0,y0);
	line(x0,0,x0,2*y0);
	x=min;
	setcolor(4);
	x1=x0+round(x*k);
	y1=y0-round(f(x)*k);
	moveto(x1,y1);
	while(x<max){
		x=x+dx;
		x2=x0+round(x*k);
		y2=y0-round(f(x)*k);
		lineto(x2,y2);
	}
}
int main(){
	khoitaodohoa();
	min=-10;max=10;
	a=1;b=-1;c=4;d=3,e=2;
	vedothi(min,max);
	getch();
	closegraph();
}
