#include <graphics.h>
#include <conio.h>
#include <iostream>

#define LEFT 1
#define RIGHT 2
#define ABOVE 3
#define BELOW 4

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

ToaDo2D h[100],luu[100];
ToaDo2D tren,duoi,giaodiem;
int n,dem;

int Round(float x){
	if (x>0) return int(x+0.5);
	else return int(x-0.5);
}

void NhapDinh(ToaDo2D P[]){
	cout<<"\nNhap so dinh da giac: ";
	cin>>n;
	for (int i=0;i<n;i++){
		cout<<"Nhap toa do dinh thu "<<i+1<<": \n";
		cout<<"x = ";
		cin>>P[i].x;
		cout<<"y = ";
		cin>>P[i].y;
	}
	P[n]=P[0];
	tren.x=100;
	tren.y=100;
	duoi.x=300;
	duoi.y=300;
}

void VeHinh(ToaDo2D P[]){
	line(tren.x,tren.y,duoi.x,tren.y);
	line(duoi.x,tren.y,duoi.x,duoi.y);
	line(duoi.x,duoi.y,tren.x,duoi.y);
	line(tren.x,duoi.y,tren.x,tren.y);
	setwritemode(XOR_PUT);
	setcolor(14);
	for (int i=0;i<n;i++)
		line(P[i].x,P[i].y,P[i+1].x,P[i+1].y);
//	getch();
	for (int i=0;i<n;i++)
		line(P[i].x,P[i].y,P[i+1].x,P[i+1].y);
	setwritemode(COPY_PUT);
}

void Giao(ToaDo2D p1, ToaDo2D p2, int canh){
	float k;
	switch (canh){
		case 1: 
			giaodiem.x=tren.x;
			k=(float)(p1.y-p2.y)/(p1.x-p2.x);
			giaodiem.y=Round((tren.x-p1.x)*k+p1.y);
			break;
		case 2: 
			giaodiem.x=duoi.x;
			k=(float)(p1.y-p2.y)/(p1.x-p2.x);
			giaodiem.y=Round((duoi.x-p1.x)*k+p1.y);
			break;
		case 3: 
			giaodiem.y=tren.y;
			k=(float)(p1.x-p2.x)/(p1.y-p2.y);
			giaodiem.x=Round((tren.y-p1.y)*k+p1.x);
			break;
		case 4: 
			giaodiem.y=duoi.y;
			k=(float)(p1.x-p2.x)/(p1.y-p2.y);
			giaodiem.x=Round((duoi.y-p1.y)*k+p1.x);
			break;
	}
}

int Trong(ToaDo2D P, int canh){
	int tam=0;
	switch (canh){
		case 1:
			if (P.x>tren.x) tam=1;
			break;
		case 2:
			if (P.x<duoi.x) tam=1;
			break;
		case 3:
			if (P.y>tren.y) tam=1;
			break;
		case 4:
			if (P.y<duoi.y) tam=1;
			break;
	}
	return tam;
}

void XenCanh(int canh){
	int truoc=0,dem=0;
	if (Trong(h[0],canh)){
		luu[dem]=h[0];
		truoc=1;
		dem++;
	}
	for (int i=1;i<n;i++){
		if (truoc)
			if (Trong(h[i],canh)){
				luu[dem]=h[i];
				truoc=1;
				dem++;
			}
			else{
				Giao(h[i-1],h[i],canh);
				luu[dem]=giaodiem;
				truoc=0;
				dem++;
			}
		else
		 	if (Trong(h[i],canh)){
		 		Giao(h[i-1],h[i],canh);
		 		luu[dem]=giaodiem;
		 		truoc=1;
		 		dem++;
		 		luu[dem]=h[i];
		 		dem++;
			}
	}
	if (truoc)
		if (Trong(h[0],canh)) truoc=1;
		else{
			Giao(h[n-1],h[0],canh);
			luu[dem]=giaodiem;
			truoc=0;
			dem++;
		}
	else
		if (Trong(h[0],canh)){
			Giao(h[n-1],h[0],canh);
			luu[dem]=giaodiem;
			truoc=0;
			dem++;
		}
		else truoc=0;
	for (int i=0;i<(dem);i++) h[i]=luu[i];
	h[dem]=luu[0];
	n=dem;
}

void XenDaGiac(){
	XenCanh(LEFT);
	XenCanh(RIGHT);
	XenCanh(ABOVE);
	XenCanh(BELOW);
}

void Ve(ToaDo2D luu[100]){
	setcolor(WHITE);
	for (int i=0;i<n;i++) line(luu[i].x,luu[i].y,luu[i+1].x,luu[i+1].y);
}

int main(){ 
  	KhoiTaoDoHoa();
  	NhapDinh(h);
  	VeHinh(h);
  	getch();
  	XenDaGiac();
  	getch();
  	Ve(h);
	getch();
	closegraph();	
}














