#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
void KhoiTaoDohoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
    setcolor(WHITE);
    cleardevice();
} 
struct ToaDo2D{
	int x,y;
};
void Circle3P(ToaDo2D A, ToaDo2D B, ToaDo2D C){ 
    int xAB=A.x-B.x; 
    int xAC=A.x-C.x; 
    int yAB=A.y-B.y; 
    int yAC=A.y-C.y; 
    int yCA=C.y-A.y; 
    int yBA=B.y-A.y; 
    int xCA=C.x-A.x; 
    int xBA=B.x-A.x; 
    int sxAC=pow(A.x,2)-pow(C.x,2); 
    int syAC=pow(A.y,2)-pow(C.y,2); 
    int sxBA=pow(B.x,2)-pow(A.x,2); 
    int syBA=pow(B.y,2)-pow(A.y,2); 
    int f=(sxAC*xAB+syAC*xAB+sxBA*xAC+syBA*xAC)/(2*(yCA*xAB-yBA*xAC)); 
    int g=(sxAC*yAB+syAC*yAB+sxBA*yAC+syBA*yAC)/(2*(xCA*yAB-xBA*yAC)); 
    int c=-pow(A.x,2)-pow(A.y,2)-2*g*A.x-2*f*A.y; 
    int h=-g; 
    int k=-f; 
    int sqr_r=h*h+k*k-c; 
    float r=sqrt(sqr_r); 
    circle(h,k,r);
    getch();
} 
int main(){
  	KhoiTaoDohoa();
  	ToaDo2D A={100,100},B={200,400},C={450,300};
    Circle3P(A,B,C);
    closegraph(); 
	return 0;
}
