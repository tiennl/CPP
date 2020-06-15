#include <graphics.h>
#include <conio.h>
#include <iostream>
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
    setcolor(WHITE);
    cleardevice();
} 
void Sector(int x0, int y0, int g1, int g2, int Rx, int Ry){
	ellipse(x0,y0,g1,g2,Rx,Ry);
	getch();
}
int main(){
  	KhoiTaoDohoa();
    Sector(250,200,0,150,100,50);
    closegraph(); 
	return 0;
}
