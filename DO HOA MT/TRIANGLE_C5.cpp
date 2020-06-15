#include <conio.h> 
#include <math.h>
#include <graphics.h>
#include <iostream>

#define PI 3.1416

using namespace std;

struct ToaDo{
	float x,y;
};

int xo,yo;
float k;

int Round(float x){
	if (x>0) return int(x+0.5);
	else return int(x-0.5);
}

void ThietLapDoHoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    setcolor(WHITE);
    cleardevice();
}

void VeTruc(){
	line(0,yo,2*xo,yo);
	line(xo,0,xo,2*xo);
}

void VeHinh(ToaDo p1, ToaDo p2, ToaDo p3){
	line(xo+Round(p1.x*k),yo-Round(p1.y*k),xo+Round(p2.x*k),yo-Round(p2.y*k));
	line(xo+Round(p2.x*k),yo-Round(p2.y*k),xo+Round(p3.x*k),yo-Round(p3.y*k));
	line(xo+Round(p3.x*k),yo-Round(p3.y*k),xo+Round(p1.x*k),yo-Round(p1.y*k));
}

void QuayDiem(ToaDo p, float alpha, ToaDo &pmoi){
	pmoi.x=p.x*cos(alpha)-p.y*sin(alpha);
	pmoi.y=p.x*sin(alpha)+p.y*cos(alpha);	
}

void QuayHinh(ToaDo p1, ToaDo p2, ToaDo p3, float alpha, ToaDo &p1moi, ToaDo &p2moi, ToaDo &p3moi){
	QuayDiem(p1,alpha,p1moi);
	QuayDiem(p2,alpha,p2moi);
	QuayDiem(p3,alpha,p3moi);
}

int main(){ 
	float goc,alpha;
	char ch;
	ToaDo p,pp,ppp,p1,p2,p3;
	ThietLapDoHoa();
	k=getmaxy()/30;
	xo=getmaxx()/2;
	yo=getmaxy()/2;
	VeTruc();
	p.x=2;
	p.y=1;
	pp.x=5;
	pp.y=7;
	ppp.x=-7;
	ppp.y=5;
	p1=p;
	p2=pp;
	p3=ppp;
	goc=PI/180;
	alpha=0;
	setwritemode(XOR_PUT);
	VeHinh(p1,p2,p3);
	do{
		ch=getch();
		switch (ch){
			case 75:
				VeHinh(p1,p2,p3);
				alpha+=goc;
				QuayHinh(p,pp,ppp,alpha,p1,p2,p3);
				VeHinh(p1,p2,p3);
				break;
			case 77:
				VeHinh(p1,p2,p3);
				alpha-=goc;
				QuayHinh(p,pp,ppp,alpha,p1,p2,p3);
				VeHinh(p1,p2,p3);
				break;		
		}
	}
	while (ch!=27);
	closegraph();	
}



