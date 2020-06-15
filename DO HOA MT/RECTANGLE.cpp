#include <conio.h> 
#include <math.h>
#include <graphics.h>
#include <iostream>

#define Step 5

using namespace std;

int xo,yo;

void ThietLapDoHoa(){ 
    int gd=0,gm; 
    initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    setcolor(WHITE);
    cleardevice();
}

void VeHinh(int xo, int yo){
	rectangle(xo,yo,xo+50,yo+30);
}

int main(){ 
  	char ch;
	ThietLapDoHoa();
	xo=getmaxx()/2;
	yo=getmaxy()/2;
	setwritemode(XOR_PUT);
	VeHinh(xo,yo);
	do{
		ch=getch();
		switch (ch){
			case 75:
				VeHinh(xo,yo);
				xo-=Step;
				VeHinh(xo,yo);
				break;
			case 77:
				VeHinh(xo,yo);
				xo+=Step;
				VeHinh(xo,yo);
				break;
			case 72:
				VeHinh(xo,yo);
				yo-=Step;
				VeHinh(xo,yo);
				break;
			case 80:
				VeHinh(xo,yo);
				yo+=Step;
				VeHinh(xo,yo);
				break;
		}
	}
	while (ch!=27);
	closegraph();	
}

