#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int n;
struct ToaDo2D
{
	int x,y;
};
ToaDo2D A,B,C,D,E,F,G;
ToaDo2D a[10];
void init()
{
	A.x=100;
	A.y=200;
	B.x=300;
	B.y=200;
	C.x=300;
	C.y=100;
	D.x=100;
	D.y=100;
	E.x=340;
	E.y=160;
	F.x=340;
	F.y=60;
	G.x=140;
	G.y=60;
}
void draw()
{
	rectangle(A.x,A.y,C.x,C.y);
	line(D.x,D.y,G.x,G.y);
	line(G.x,G.y,F.x,F.y);
	line(F.x,F.y,C.x,C.y);
	line(F.x,F.y,E.x,E.y);
	line(E.x,E.y,B.x,B.y);
}
void Scanline(){
	n=4;
	a[1].x=B.x;
	a[1].y=B.y;
	a[2].x=C.x;
	a[2].y=C.y;
	a[3].x=F.x;
	a[3].y=F.y;
	a[4].x=E.x;
	a[4].y=E.y;
	int x,minx,maxx;
	minx=a[1].x;
	maxx=a[1].x;
	for (int i=2;i<=n;i++){
		if (a[i].x<minx) minx=a[i].x;
		if (a[i].x>maxx) maxx=a[i].x;
	}
	for (x=minx+1;x<=maxx-1;x++){
		int m=0,z[50];
		for (int i=1;i<=n;i++){
			int t=i+1;
			if (i==n) t=1;
			int s=i-1;
			if (i==1) s=n;
			if (x==a[i].x){
				if ((x>min(a[s].x,a[t].x)) && (x<max(a[s].x,a[t].x))){
					m++;
					z[m]=a[i].y;
				}
				else{
					m++;
					z[m]=a[i].y;
					m++;
					z[m]=a[i].y;
				}
			}
			else if ((x>min(a[i].x,a[t].x)) && (x<max(a[t].x,a[i].x))){
				++m;
				float r;
				r=(a[t].y-a[i].y);
				r/=(a[t].x-a[i].x);
				z[m]=(int)(r*(x-a[i].x))+a[i].y;
			}
		}
		for (int i=1;i<m;i++)
			for (int k=i+1;k<=m;k++)
				if (z[i]>z[k]){
					int tg=z[i];
					z[i]=z[k];
					z[k]=tg;
				}
		for (int k=1;k<=m-1;k++)
			if (k%2!=0) line(x,z[k],x,z[k+1]);
	}
}
int main()
{
	init();
	int driver= DETECT,mode;
	initgraph(&driver,&mode,"");
	settextstyle(0,0,2);
	outtextxy(10,20,"Ngo Le Thuy Tien");
	draw();
	getch();
	Scanline();
	getch();
}

