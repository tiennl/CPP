//Chuong trinh tao Menu POPUP che do GRAPHICS
//Copy right by Pham Anh Phuong
#include <graphics.h>
#include <conio.h>
#include<bits/stdc++.h>
#define mau1 15
#define mau2 8
#define maumn 7
#define XTop 200
#define YTop 100
#define Dy 32
#define Dx 250
#define PI 3.1416
using namespace std;
struct ToaDo2D 
{ 
  int x,y; 
}; 
  
int SoDong;
float a,b,c,d,e,Min,Max;
void KhoiTaoDohoa() 
{ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
} 

int angle(int x, int y)
{
    int kq=abs((int) ((atan((float)y/x)*180/PI)));
    if(x<0&&y>0) kq+=90;
    if(x<0&&y<0) kq=180-kq;
    if(x>0&&y<0) kq=360-kq;
    return kq;
}


int STamGiac(ToaDo2D a,ToaDo2D b, ToaDo2D c)
{
	return abs((b.x*a.y-a.x*b.y)+(c.x*b.y-b.x*c.y)+(a.x*c.y-c.x*a.y));
}
void Baitap0()
{
	system("cls");
	closegraph();
	ToaDo2D a,b,c;
	cout<<"A.x=";cin>>a.x;
	cout<<"A.y=";cin>>a.y;
	cout<<"B.x=";cin>>b.x;
	cout<<"B.y=";cin>>b.y;
	cout<<"C.x=";cin>>c.x;
	cout<<"C.y=";cin>>c.y;
	cout<<"Dien tich tam giac ABC:"<<(float)STamGiac(a,b,c)/2<<"px^2";
	getch();
}
int DienTich(ToaDo2D p[],int n)
{
	int s=(p[0].x*p[n-1].y-p[n-1].x*p[0].y);
	for(int i=1;i<n;i++)
	s+=(p[i].x*p[i-1].y-p[i-1].x*p[i].y);
	return abs(s);
}
void Baitap1()
{
	system("cls");
	closegraph();
	int n;
	cout<<"Nhap so diem cua da giac loi:";cin>>n;
	ToaDo2D p[n+10];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap toa do diem thu "<<i+1<<":\nNhap x=";cin>>p[i].x;
		cout<<"Nhap y=";cin>>p[i].y;
	}
	cout<<"Dien tich cua da giac:"<<(float)DienTich(p,n)/2<<"px^2";
	getch();
	
}
bool KiemTra(int x,int y,ToaDo2D p[],int n)
{
	int s=DienTich(p,n);
	ToaDo2D a;
		a.x=x;a.y=y;
	int sum=STamGiac(p[0],p[n-1],a);
	for(int i=1;i<n;i++)
	{
		ToaDo2D a;
		a.x=x;a.y=y;
		sum+=STamGiac(p[i],p[i-1],a);
	}
	
	if(sum==s) return true;
	return false;
}
void Baitap2()
{
	system("cls");
	closegraph();
	int n,x,y;
	cout<<"Nhap so diem cua da giac loi:";cin>>n;
	ToaDo2D p[n+10];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap toa do diem thu "<<i+1<<":\nNhap x=";cin>>p[i].x;
		cout<<"Nhap y=";cin>>p[i].y;
	}
	cout<<"x=";cin>>x;
	cout<<"y=";cin>>y;
	string s="Diem da cho nam ";
	if(KiemTra(x,y,p,n)) s+="trong";
	else s+="ngoai";
	s+=" da giac";
	cout<<s;
	getch();
}
void FillRec(int x1,int y1,int x2,int y2,int color)
{
	setcolor(color);
	if(x1>x2)
	{
		int xtemp=x1,ytemp=y1;
		x1=x2;x2=xtemp;
		y1=y2;y2=ytemp;
	}
	for(int i=x1;i<=x2;i++)
	{
		line(i,y1,i,y2);
	}
}


void Baitap3()
{
	system("cls");
	closegraph();
	int x1,y1,x2,y2,color;
	
	
	cout<<"Nhap toa do diem tren bai trai cua hcn:\nNhap x:";
	cin>>x1;
	cout<<"Nhap y:";cin>>y1;
	cout<<"Nhap toa do diem duoi ben phai cua hcn:\nNhap x:";cin>>x2;
	cout<<"Nhap y:";cin>>y2;
	cout<<"Nhap ma mau:";cin>>color;
	initwindow(600,500);
	FillRec(x1,y1,x2,y2,color);
	

	getch();
}
int round(float x)
{
	if (x>0) return int (x+0.5);
	else return int (x-0.5);
}
float X(float a,int r)
{
	return r*cos(a*PI/180);
}
float Y(float a,int r)
{
	return r*sin(a*PI/180);
}
void FillEllipse(int x0,int y0,int Rx,int Ry,int color)
{
	setcolor(color);
	int x2,y2;
	float x,dx,k;
	dx=0.1;
	x=0;
	while(x<=180)
	{
	x2=x0+round(X(x,Rx));
	y2=round(Y(x,Ry));
	line(x2,y0-y2,x2,y0+y2);
	x+=dx;
	}
}
void Baitap4()
{
	system("cls");
	closegraph();
	int x,y,Rx,Ry,color;
	cout<<"Nhap toa do tam:\nNhap x:";
	cin>>x;
	cout<<"Nhap y:";cin>>y;
	cout<<"Nhap ban kinh theo truc x:";cin>>Rx;
	cout<<"Nhap ban kinh theo truc y:";cin>>Ry;
	cout<<"Nhap ma mau:";cin>>color;
	initwindow(600,500);
	FillEllipse(x,y,Rx,Ry,color);
	getch();
}
void FillSector(int x0,int y0,int Rx,int Ry,int g1,int g2,int color)
{
	setcolor(color);
	int x2,y2;
	float x,dx,k;
	dx=0.1;
	x=g1;
	while(x<=g2)
	{
	x2=x0+round(X(x,Rx));
	y2=y0-round(Y(x,Ry));
	line(x2,y2,x2,y0);
	x+=dx;
	}
}
void Baitap5()
{
	system("cls");
	closegraph();
	int x,y,Rx,Ry,color,g1,g2;
	cout<<"Nhap toa do tam:\nNhap x:";
	cin>>x;
	cout<<"Nhap y:";cin>>y;
	cout<<"Nhap ban kinh theo truc x:";cin>>Rx;
	cout<<"Nhap ban kinh theo truc y:";cin>>Ry;
	cout<<"Nhap goc bat dau:";cin>>g1;
	cout<<"Nhap goc ket thuc:";cin>>g2;
	cout<<"Nhap ma mau:";cin>>color;
	initwindow(600,500);
	FillSector(x,y,Rx,Ry,g1,g2,color);
	getch();
}
void Donut(int x0,int y0,int Rmin,int Rmax,int color)
{
	FillEllipse(x0,y0,Rmax,Rmax,color);
	FillEllipse(x0,y0,Rmin,Rmin,0);
}
void Baitap6()
{
	system("cls");
	closegraph();
	int x,y,Rmin,Rmax,color;
	cout<<"Nhap toa do tam:\nNhap x:";
	cin>>x;
	cout<<"Nhap y:";cin>>y;
	cout<<"Nhap Rmin:";cin>>Rmin;
	cout<<"Nhap Rmax:";cin>>Rmax;
	cout<<"Nhap ma mau:";cin>>color;
	initwindow(600,500);
	Donut(x,y,Rmin,Rmax,color);
	getch();
}
void Box(int x1,int y1,int x2,int y2,int MauVienTren,int MauVienDuoi,int MauNen)
{
   setfillstyle(1,MauNen);
   bar(x1,y1,x2,y2);
   setcolor(MauVienTren);
   for(int i=0;i<=1;i++)
   {
       moveto(x1-i,y2+i);
       lineto(x1-i,y1-i);
       lineto(x2+i,y1-i);
   }

   setcolor(MauVienDuoi);
   for(int i=0;i<=1;i++)
   {
      moveto(x2+i,y1-i);
      lineto(x2+i,y2+i);
      lineto(x1-i,y2+i);
   }
}
void Ve_menu(int Xdau,int Ydau,int DeltaX,int DeltaY,int chon,int SoDong, char *DongMN[])
{
	setbkcolor(0);
	cleardevice();
   	for (int i=0;i<SoDong;i++)
	{
       if (i==chon) Box(Xdau,Ydau+i*DeltaY+6,Xdau+DeltaX,Ydau+i*DeltaY+DeltaY,mau2,mau1,maumn);
       else Box(Xdau,Ydau+i*DeltaY+6,Xdau+DeltaX,Ydau+i*DeltaY+DeltaY,mau1,mau2,maumn);
       outtextxy(Xdau+20,Ydau+15+i*DeltaY,DongMN[i]);
	}
}
main()
{
  char ch,*st[20];

  st[0]="1.Dien tich tam giac";
  st[1]="2.Dien tich da giac loi";
  st[2]="3.KiemTra";
  st[3]="4.To mau HCN";
  st[4]="5.To mau Ellipse";
  st[5]="6.To mau hinh quat Ellipse";
  st[6]="7.To mau hinh vanh khan";
  int x0=25,y0=5,chon=0,luuchon,sodong=7,ok=FALSE;
  KhoiTaoDohoa();
  settextstyle(0,0,2);
//  Ve_menu(x0,y0,chon,sodong,st);
  Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
  do
  {
  ch=getch(); //Nhan mot phim
  switch (ch)
	{
		case 72: //phim len
			luuchon=chon;
			chon--;
			if(chon<0) chon=sodong-1;
            Box(XTop,YTop+luuchon*Dy+6,XTop+Dx,YTop+luuchon*Dy+Dy,mau1,mau2,maumn);
            outtextxy(XTop+20,YTop+15+luuchon*Dy,st[luuchon]);
            Box(XTop,YTop+chon*Dy+6,XTop+Dx,YTop+chon*Dy+Dy,mau2,mau1,maumn);
            outtextxy(XTop+20,YTop+15+chon*Dy,st[chon]);
			break;
		case 80://phim xuong
			luuchon=chon;
			chon++;
			if(chon==sodong) chon=0;
            Box(XTop,YTop+luuchon*Dy+6,XTop+Dx,YTop+luuchon*Dy+Dy,mau1,mau2,maumn);
            outtextxy(XTop+20,YTop+15+luuchon*Dy,st[luuchon]);
            Box(XTop,YTop+chon*Dy+6,XTop+Dx,YTop+chon*Dy+Dy,mau2,mau1,maumn);
            outtextxy(XTop+20,YTop+15+chon*Dy,st[chon]);
			break;
		case 13: //phim ENTER
		ok=TRUE; break;
	}
	if (ok==TRUE) //Neu phim ENTER duoc nhan
	{
	  switch (chon)
		{
		 case 0:
			Baitap0();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 1:
			Baitap1();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 2:
			Baitap2();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 3:
			Baitap3();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;	
		 case 4:
			Baitap4();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;	
		 case 5:
		 	Baitap5();
		 	Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
					 	
		case 6:
		 	Baitap6();
		 	Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;	
		 case 7: exit(0);
		 
		}
	  ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
	}
  }
  while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}

