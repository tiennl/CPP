#include <graphics.h>
#include <conio.h>
#include <iostream>
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
    setcolor(GREEN);
    cleardevice();
} 
int min(int a, int b){
	return (a<b)?a:b;
}
int max(int a, int b){
	return (a>b)?a:b;
}
struct ToaDo{
	int x,y;
};
double Stamgiac(ToaDo A, ToaDo B, ToaDo C){
	return abs((B.x*A.y-A.x*B.y) + (C.x*B.y-B.x*C.y) + (A.x*C.y-C.x*A.y))/2;
}
bool check(ToaDo P, ToaDo A, ToaDo B, ToaDo C){
	double s1=Stamgiac(A,B,P)+Stamgiac(B,C,P)+Stamgiac(A,C,P);
	double s2=Stamgiac(A,B,C);
	return s1==s2;
}
int main(){
  	KhoiTaoDohoa();
	ToaDo A={100,200},B={300,400},C={100,350},P;
	int xmin=0,xmax=0,ymin=0,ymax=0;
	xmin=min(C.x,min(A.x,B.x));
	xmax=max(C.x,max(A.x,B.x));
	ymin=min(C.y,min(A.y,B.y));
	ymax=max(C.y,max(A.y,B.y));
	for (int i=xmin;i<=xmax;i++)
		for (int j=ymin;j<=ymax;j++){
			P.x=i;
			P.y=j;
			if (check(P,A,B,C)) putpixel(P.x,P.y,GREEN);
		}	
	getch();
	return 0;
}
