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

void TrongNgoai(ToaDo2D A, ToaDo2D B){
	ToaDo2D P,Q,M;
	P=A;
	Q=B;
	while (abs(P.x-Q.x)+abs(P.y-Q.y)>2){
		M.x=(P.x+Q.x)/2;
		M.y=(P.y+Q.y)/2;
		if (Ma(M)==0) P=M;
		else Q=M;
	}
	line(A.x,A.y,P.x,P.y);
}

void clip(ToaDo2D A, ToaDo2D B){
	ToaDo2D P,Q,M;
	if (Ma(A)==0 && Ma(B)==0)
		line(A.x,A.y,B.x,B.y);
	else if (Ma(A)==0 && Ma(B)!=0) 
		TrongNgoai(A,B);
	else if (Ma(A)!=0 && Ma(B)==0)
		TrongNgoai(B,A);
	else if ((Ma(A) & Ma(B))==0){
		P=A;
		Q=B;
		M.x=(P.x+Q.x)/2;
		M.y=(P.y+Q.y)/2;
		while (Ma(M)!=0 && (Ma(P) & Ma(Q))==0){
			if ((Ma(P) & Ma(M))!=0) P=M;
			else Q=M;
			M.x=(P.x+Q.x)/2;
			M.y=(P.y+Q.y)/2;
		}
		if (Ma(M)==0){
			TrongNgoai(M,P);
			TrongNgoai(M,Q);
		}
	}
}

int main(){ 
  	KhoiTaoDoHoa();
	Nhap();
	VeHinh();
	clip(A,B);
	getch();
	closegraph();	
}
