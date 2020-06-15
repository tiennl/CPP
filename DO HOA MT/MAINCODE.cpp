//Chuong trinh tao Menu POPUP che do GRAPHICS
//Copy right by Pham Anh Phuong
#include <graphics.h>
#include <conio.h>

#define mau1 15
#define mau2 8
#define maumn 7
#define XTop 200
#define YTop 100
#define Dy 32
#define Dx 250

int SoDong;
float a,b,c,d,min,max;
void KhoiTaoDohoa() 
{ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
} 

int round(float x)
{
	if (x>0) return int (x+0.5);
	else return int (x-0.5);
}
float f(float x)
{
  return(a*x*x*x+b*x*x+c*x+d);
}

void vedothi(float min,float max)
{
 int x0,y0,x1,y1,x2,y2;
 float x,dx,k;
 x0=getmaxx()/2;
 y0=getmaxy()/2;
 k=(float)getmaxx()/30;
 dx=0.0001;
 setbkcolor(15);
 cleardevice();
 setcolor(1);
 line(0,y0,2*x0,y0);
 line(x0,0,x0,2*y0);
 x=min;
 setcolor(1);
 x1=x0+round(x*k);
 y1=y0-round(f(x)*k);
 moveto(x1,y1);
 while (x<max)
 {
    x=x+dx;
    x2=x0+round(x*k);
    y2=y0-round(f(x)*k);
    lineto(x2,y2);
 }
}
void Baitap0()
{
	cleardevice();
    min=-10;max=10;
    a=1;b=-3;c=-1;d=2;//,e=-2;
    vedothi(min,max);
	getch();
}

void Baitap1()
{
	cleardevice();
	outtext("Xin loi, tui chua lam");
	getch();
	
}void Baitap2()
{
	cleardevice();
	outtext("Buon ngu qua, chua lam kip");
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

  st[0]="Ve ham bac 3";
  st[1]="Ve cung tron";
  st[2]="Ve da giac deu";
  int x0=25,y0=5,chon=0,luuchon,sodong=3,ok=FALSE;
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
		 case 3: exit(0);
		}
	  ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
	}
  }
  while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}

