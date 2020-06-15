#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

#define TRUE 1
#define FALSE 0

using namespace std;

void KhoiTaoDoHoa() 
{ 
    int gd=DETECT,gm; 
    initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    setcolor(WHITE);
    cleardevice();
}
struct ToaDo2D{
	int x,y;
};

int Round(float x){
	if (x>0) return int(x+0.5);
	else return int(x-0.5);
}

int random(int minN, int maxN){
	return minN+rand()%(maxN+1-minN);
}

int cliptest(float p, float q, float &u1, float &u2){
	float r;
	int clip=TRUE;
	if (p<0){
		r=q/p;
		if (r>u2) clip=FALSE;
		else if (r>u1) u1=r;
	}
	else if (p>0){
		r=q/p;
		if (r<u1) clip=FALSE;
		else if (r<u2) u2=r;
	}
	else if (q<0) clip=FALSE;
	return clip;
}

void clip(ToaDo2D A, ToaDo2D B, ToaDo2D Tren, ToaDo2D Duoi){
	float u1=0,u2=1,dx,dy;
	dx=B.x-A.x;
	if (cliptest(-dx,A.x-Tren.x,u1,u2))
		if (cliptest(dx,Duoi.x-A.x,u1,u2)){
			dy=B.y-A.y;
			if (cliptest(-dy,A.y-Tren.y,u1,u2))
				if (cliptest(dy,Duoi.y-A.y,u1,u2)){
					if (u2<1){
						B.x=A.x+Round(u2*dx);
						B.y=A.y+Round(u2*dy);
					}
					if (u1>0){
						A.x+=Round(u1*dx);
						A.y+=Round(u1*dy);
					}
					line(A.x,A.y,B.x,B.y);
				}
		}
}

int main(){ 
  	KhoiTaoDoHoa();
	char c;
	ToaDo2D Tren,Duoi,A,B;
	Tren.x=150;
	Tren.y=100;
	Duoi.x=400;
	Duoi.y=300;
	rand();
	rectangle(Tren.x,Tren.y,Duoi.x,Duoi.y);
	setwritemode(XOR_PUT);
//	do{
		A.x=200;
		A.y=0;
		B.x=300;
		B.y=500;
		line(A.x,A.y,B.x,B.y);
		getch();
		line(A.x,A.y,B.x,B.y);
		clip(A,B,Tren,Duoi);
		getch();
//	}
//	while (c!=27);
	closegraph();	
}
