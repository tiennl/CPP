#include <graphics.h>
#include <conio.h>
#include <iostream>
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
    setcolor(WHITE);
    cleardevice();
} 
void Arc(int x0, int y0, int g1, int g2, int R){
	arc(x0,y0,g1,g2,R);
	getch();
}
int main(){
  	KhoiTaoDohoa();
    Arc(250,250,155,300,100);
    closegraph(); 
	return 0;
}
