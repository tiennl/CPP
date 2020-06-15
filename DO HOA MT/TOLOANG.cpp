#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
int MauNen;
void KhoiTaoDohoa() 
{ 
    int gd=DETECT,gm; 
    initgraph(&gd,&gm,""); 
    setcolor(WHITE);
    cleardevice();
}
struct ToaDo2D{
	int x,y;
};
void Nhap(int &n, int &x, int &y, ToaDo2D a[]){
	cout<<"\nNhap so dinh cho da giac:";
	cin>>n;
	for (int i=1;i<=n;i++){
		cout<<"\na["<<i<<"].x=";
		cin>>a[i].x;
		cout<<"\na["<<i<<"].y=";
		cin>>a[i].y;
	}
	cout<<"\nNhap toa do dinh P:"<<endl;
	cout<<"\nNhap x=";
	cin>>x;
	cout<<"\nNhap y=";
	cin>>y;
}
void VeDaGiac(int n, ToaDo2D a[], int color){
	setcolor(WHITE);
	for (int i=1;i<=n;i++){
		int j;
		if (i==n) j=1;
		else j=i+1;
		line(a[i].x,a[i].y,a[j].x,a[j].y);
	}
}
void ToLoang(int x, int y, int color){
	if (getpixel(x,y)==MauNen && x>0 && x<getmaxx() && y>0 && y<getmaxy()){
		putpixel(x,y,color);
		ToLoang(x+1,y,color);
		ToLoang(x-1,y,color);
		ToLoang(x,y+1,color);
		ToLoang(x,y-1,color);
	}
}
int main()
{ 
  	KhoiTaoDohoa();
	int x,y,n;
	ToaDo2D a[100];
	Nhap(n,x,y,a);
	VeDaGiac(n,a,WHITE);
	MauNen=getpixel(x,y);
	ToLoang(x,y,WHITE);
	getch();
	closegraph();	
}

