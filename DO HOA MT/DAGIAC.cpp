#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
void KhoiTaoDohoa() 
{ 
    int gd=0,gm; 
    initgraph(&gd,&gm,"d:\\tc\\bgi"); 
    setcolor(WHITE);
    cleardevice();
}
struct ToaDo2D{
	int x,y;
};
void Nhap(int &n, ToaDo2D a[]){
	cout<<"\nNhap so dinh cho da giac:";
	cin>>n;
	for (int i=1;i<=n;i++){
		cout<<"\na["<<i<<"].x=";
		cin>>a[i].x;
		cout<<"\na["<<i<<"].y=";
		cin>>a[i].y;
	}
}
void VeDaGiac(int n, ToaDo2D a[]){
	int i,j;
	for (int i=1;i<=n;i++){
		if (i==n) j=1;
		else j=i+1;
		line(a[i].x,a[i].y,a[j].x,a[j].y);
	}
}
int min(int a, int b){
	return (a<b)?a:b;
}
int max(int a, int b){
	return (a>b)?a:b;
}
void Scanline(int n, ToaDo2D a[]){
	int x,minx,maxx;
	minx=a[1].x;
	maxx=a[1].x;
	for (int i=2;i<=n;i++){
		if (a[i].x<minx) minx=a[i].x;
		if (a[i].x>maxx) maxx=a[i].x;
	}
	for (x=minx+1;x<=maxx-1;x++){
		int m=0,z[50];
		for (int i=1;i<=n;i++){
			int t=i+1;
			if (i==n) t=1;
			int s=i-1;
			if (i==1) s=n;
			if (x==a[i].x){
				if ((x>min(a[s].x,a[t].x)) && (x<max(a[s].x,a[t].x))){
					m++;
					z[m]=a[i].y;
				}
				else{
					m++;
					z[m]=a[i].y;
					m++;
					z[m]=a[i].y;
				}
			}
			else if ((x>min(a[i].x,a[t].x)) && (x<max(a[t].x,a[i].x))){
				++m;
				float r;
				r=(a[t].y-a[i].y);
				r/=(a[t].x-a[i].x);
				z[m]=(int)(r*(x-a[i].x))+a[i].y;
			}
		}
		for (int i=1;i<m;i++)
			for (int k=i+1;k<=m;k++)
				if (z[i]>z[k]){
					int tg=z[i];
					z[i]=z[k];
					z[k]=tg;
				}
		for (int k=1;k<=m-1;k++)
			if (k%2!=0) line(x,z[k],x,z[k+1]);
	}
}
int main()
{ 
  	KhoiTaoDohoa();
	int n;
	ToaDo2D a[100];
	Nhap(n,a);
	VeDaGiac(n,a);
	Scanline(n,a);
	getch();
	closegraph();	
}

