#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
} 
void C(int x1, int y1, int x2, int y2, int n){
	if (n>0){
		int u=(x1+x2+y2-y1)/2;
		int v=(y1+y2-x2+x1)/2;
		C(x1,y1,u,v,n-1);
		C(u,v,x2,y2,n-1);1,x2,y2);
}
void Dragon(int x1, int y1, int x2, int y2, int n){
	if (n>0){
		int u=(x1+x2+y2-y1)/2;
		int v=(y1+y2-x2+x1)/2;
		Dragon(x1,y1,u,v,n-1);
		Dragon(x2,y2,u,v,n-1);
	}
	else line(x1,y1,x2,y2);
}
int main(){
	int n=15;
	KhoiTaoDohoa();
//	Dragon(150,300,450,300,n);
	C(150,300,450,300,n);
	getch();
	closegraph();
}
