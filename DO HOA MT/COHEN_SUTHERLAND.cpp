#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#define LEFT 1
#define RIGHT 2
#define BELLOW 4
#define ABOVE 8
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

ToaDo2D Tren,Duoi,A,B;

void Nhap(){
	Tren.x=150;
	Tren.y=100;
	Duoi.x=400;
	Duoi.y=300;
	cout<<"\nA.x=";
	cin>>A.x;
	cout<<"\nA.y=";
	cin>>A.y;
	cout<<"\nB.x=";
	cin>>B.x;
	cout<<"\nB.y=";
	cin>>B.y;
}

void VeHinh(){
	rectangle(Tren.x,Tren.y,Duoi.x,Duoi.y);
	setwritemode(XOR_PUT);
	line(A.x,A.y,B.x,B.y);
	getch();
	line(A.x,A.y,B.x,B.y);
}

int Ma(ToaDo2D P){
	int S=0;
	if (P.x<Tren.x) S=S|LEFT;
	if (P.x>Duoi.x) S=S|RIGHT;
	if (P.y>Duoi.y) S=S|BELLOW;
	if (P.y<Tren.y) S=S|ABOVE;
	return S;
}

int Round(float x){
	if (x>0) return int(x+0.5);
	else return int(x-0.5);
}

void Swap(ToaDo2D &A, ToaDo2D &B){
	ToaDo2D t=A;
	A=B;
	B=t;
}

void clip(ToaDo2D A, ToaDo2D B, ToaDo2D Tren, ToaDo2D Duoi){
	int stop=FALSE,draw=FALSE;
	while (stop!=TRUE){
		if (Ma(A)==0 && Ma(B)==0){
			stop=TRUE;
			draw=TRUE;
		}
		else 
			if ((Ma(A) & Ma(B))!=0) stop=TRUE;
			else{
				if ((Ma(A) & Ma(B))==0 && (Ma(A)!=0 || Ma(B)!=0)){
					if (Ma(A)==0) Swap(A,B);
					float m=float(B.y-A.y)/(B.x-A.x);
					if ((Ma(A)&LEFT)!=0){
						A.y=A.y+Round(m*(Tren.x-A.x));
						A.x=Tren.x;
					}
					else if ((Ma(A)&RIGHT)!=0){
						A.y=A.y+Round(m*(Duoi.x-A.x));
						A.x;Duoi.x;
					}
					else if ((Ma(A)&ABOVE)!=0){
						A.x=A.x+Round(float(Tren.y-A.y)/m);
						A.y=Tren.y;
					}
					else if ((Ma(A)&BELLOW)!=0){
						A.x=A.x+Round(float(Duoi.y-A.y)/m);
						A.y=Duoi.y;
					}
				}
			}
		}
	if (draw) line(A.x,A.y,B.x,B.y);
}

int main(){ 
  	KhoiTaoDoHoa();
	Nhap();
	VeHinh();
	clip(A,B,Tren,Duoi);
	getch();
	closegraph();	
}

