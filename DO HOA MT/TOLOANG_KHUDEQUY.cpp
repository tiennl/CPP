#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

void KhoiTaoDohoa() 
{ 
    int gd=DETECT,gm; 
    initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    setcolor(WHITE);
    cleardevice();
}

struct ToaDo{
	int x,y;
};

struct DANHSACH{
	int x,y;
	DANHSACH *next;
}*Stack;

void PUSH(int x, int y, DANHSACH **Stack){
	DANHSACH *p = new DANHSACH;
	p->x=x;
	p->y=y;
	p->next=NULL;
	if (*Stack==NULL) *Stack=p;
	else{
		DANHSACH *q=*Stack;
		while (q->next!=NULL) q=q->next;
		q->next=p;
	}
}

void POP(int &x, int &y, DANHSACH **Stack){
	DANHSACH *p;
	if (*Stack!=NULL){
		p=*Stack;
		*Stack=(*Stack)->next;
		x=p->x;
		y=p->y;
		delete p;
	}
}

void NhapDaGiac(int &n, int &x, int &y, ToaDo a[]){
	cout<<"\nNhap vao so dinh cua da giac n = ";
	cin>>n;
	for (int i=1;i<=n;i++){
		cout<<"Toa do dinh P["<<i<<"].x = ";
		cin>>a[i].x;
		cout<<"Toa do dinh P["<<i<<"].y = ";
		cin>>a[i].y;
	}
	cout<<"Nhap diem (x,y) thuoc da giac:\n";
	cout<<"Nhap x = ";
	cin>>x;
	cout<<"Nhap y = ";
	cin>>y;
}

void VeDaGiac(int n, ToaDo a[], int color){
	setcolor(WHITE);
	for (int i=1;i<=n;i++){
		int j;
		if (i==n) j=1;
		else j=i+1;
		line(a[i].x,a[i].y,a[j].x,a[j].y);
	}
}

void ToLoang(int x, int y, int color){
	Stack=NULL;
	PUSH(x,y,&Stack);
	int tx,ty;
	int MauNen=getpixel(x,y);
	while (Stack!=NULL){
		POP(x,y,&Stack);
		if (getpixel(x,y)==MauNen && x>0 && x<getmaxx() && y>0 && y<getmaxy()){
			putpixel(x,y,color);
			tx=x+1;
			ty=y;
			if (getpixel(tx,ty)==MauNen) 
				PUSH(tx,ty,&Stack);
			tx=x-1;
			ty=y;
			if (getpixel(tx,ty)==MauNen)
				PUSH(tx,ty,&Stack);
			tx=x;
			ty=y-1;	
				if (getpixel(tx,ty)==MauNen)
				PUSH(tx,ty,&Stack);
			tx=x;
			ty=y+1;
			if (getpixel(tx,ty)==MauNen)
				PUSH(tx,ty,&Stack);
		}
	}		
}

int main()
{ 
  	KhoiTaoDohoa();
	int x,y,n;
	ToaDo a[100];
	NhapDaGiac(n,x,y,a);
	VeDaGiac(n,a,WHITE);
	ToLoang(x,y,WHITE);
	getch();
	closegraph();	
}
