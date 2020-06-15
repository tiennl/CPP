#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#define PI 3.1416
using namespace std;
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
} 
int Round(float x){
	if (x>0) return int(x+0.5);
	else return int(x-0.5);
}
void Koch(float dir, float len, int n){
	if (n>0){
		Koch(dir,len/3,n-1);
		dir+=60;
		Koch(dir,len/3,n-1);
		dir-=120;
		Koch(dir,len/3,n-1);
		dir+=60;
		Koch(dir,len/3,n-1);
	}
	else linerel(Round(len*cos(dir*PI/180)),Round(len*sin(dir*PI/180)));
}
int main(){
	KhoiTaoDohoa();
	float goc=180,len=500;
	int n=4;
	moveto(500,200);
	Koch(goc,len,n);
	getch();
	closegraph();
}
