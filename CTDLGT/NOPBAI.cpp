#include "windows.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

#ifdef WIN32
void gotoxy(int x, int y)
{
  COORD cur = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
} 
#else
void gotoxy(int x, int y)
{
  printf("\033[%dG\033[%dd", x+1, y+1);
}
#endif

int textcolor(int Color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE); 
  return SetConsoleTextAttribute(h, Color);
}

#define CYAN 10
#define YELLOW 14

int n=0,m=0, A[50],B[50];

int KTra(int x,int n,int A[])
{
  for(int i=0;i<n;i++)
   if(x==A[i]) return 1;
  return 0;
}

void Insert(int x,int &n,int A[])
{
  if(KTra(x,n,A)==0)
  {
   A[n]=x;
   n++;
  }
}

void View(int n, int A[])
{
  cout<<"\n";
  for(int i=0;i<n;i++)
   cout<<A[i]<<"  ";
}

void Bosung(int &n,int A[])
{
  char ch;
  int x;
  do
  {
    cout<<"\nNhap x= "; cin>>x;
    Insert(x,n,A);
    cout<<"\nNhan <ESC> de ket thuc nhap!";
    ch=getch();
  }
  while(ch!=27);
}

void Giao(int n,int A[],int m,int B[])
{
  for(int i=0;i<n;i++)
   if(KTra(A[i],m,B))
     cout<<A[i]<<"  ";
  cout<<"\n";
}

void Baitap1()
{
  system("cls");
  cout<<"\nNhap tap hop A:\n";
  Bosung(n,A);
  View(n,A);
  getch();
}

void Baitap2()
{
  system("cls");
  cout<<"\nNhap tap hop B:\n";
  Bosung(m,B);
  View(m,B);
  getch();
}

void Baitap3()
{
  system("cls");
  cout<<"\nNhap tap hop A:\n";
  View(n,A);
  getch();
  cout<<"\nNhap tap hop A:\n";
  View(m,B);
  getch();
  cout<<"\nGiao cua 2 tap hop A&B:\n";
  Giao(n,A,m,B);
  getch();
}

void Baitap4()
{
  system("cls");
  cout<<"\nXin loi chua lam!!!\n";
  getch();
}

void Baitap5()
{
  system("cls");
  float a,b,c,p,s;
  cout<<endl<<"Nhap a = "; cin>>a;
  cout<<endl<<"Nhap b = "; cin>>b;
  cout<<endl<<"Nhap c = "; cin>>c;
  p = (a+b+c)/2;
  s = sqrt(p*(p-a)*(p-b)*(p-c));
  cout<<endl<<"Dien tich = "<<s;
  getch();    
}

void Baitap6()
{
  system("cls");
  cout<<endl<<"Tim UCLN cua 2 so a,b";
  cout<<endl<<"Xin loi, chua cai dat xong";
  getch();    
}

int Tong(int n,int a[])
{
	if(n==0) return 0;
	else return a[n] + Tong(n-1,a);
}
void Nhap(int &n,int a[])
{
	cout<<endl<<"Nhap n = "; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<endl<<"A["<<i<<"]=";
		cin>>a[i];
	}
}
void Baitap7()
{
  system("cls");
  cout<<endl<<"Tinh tong mang";
  int n, a[100];
  Nhap(n,a);
  cout<<endl<<"Tong mang = "<<Tong(n,a);  
  getch();    
}
//Viet xau s ra man hinh tai toa do (x,y) voi mau la color
void Write(char *s,int x,int y, int color)
{
  textcolor(color);
  gotoxy(x,y); cout<<s;
  textcolor(15);
}

void Khung(int x1,int y1,int x2,int y2)
{ int x,y;
  gotoxy(x1,y1); cout<<"É";
  gotoxy(x2,y1); cout<<"»";
  gotoxy(x1,y2); cout<<"È";
  gotoxy(x2,y2); cout<<"¼";
  for(x=x1+1;x<x2;x++)
	 {
		gotoxy(x,y1); cout<<"Í";
		gotoxy(x,y2); cout<<"Í";
	 }
  for(y=y1+1;y<y2;y++)
	 {
		gotoxy(x1,y); cout<<"º";
		gotoxy(x2,y); cout<<"º";
	 }
}
/*Tao ra menu tai toa do (x0,y0) voi n dong luu trong bien s
chon: dong menu hien thoi (khac mau voi cac dong khac) */
void Ve_menu(int x0,int y0,int chon,int n,char *s[])
{
  system("cls");
  Khung(x0-2,y0-1,x0+30,y0+n);
  for(int i=0;i<n;i++)
	 if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 else Write(s[i],x0,y0+i,YELLOW);
  Write("Copyright (c) 2016 by Pham Anh Phuong.",x0-4,y0+n+5,10);
}

main()
{
  char ch,*st[20];
  system("cls");
  st[0]="Khoi tao tap hop A";
  st[1]="Khoi tao tap hop B";
  st[2]="Giao cua 2 tap A & B";
  st[3]="Hop cua hai tap hop";
  st[4]="Tinh dien tich tam giac";
  st[5]="Tim UCLN";
  st[6]="Tinh tong";
  st[7]="<ESC> Ket thuc chuong trinh!";
  int x0=25,y0=10,chon=0,luuchon,sodong=8,ok=FALSE;
  Ve_menu(x0,y0,chon,sodong,st);
  do
  {
  ch=getch(); //Nhan mot phim
  switch (ch)
	{
		case 72: //phim len
			luuchon=chon;
			chon--;
			if(chon<0) chon=sodong-1;
			Write(st[luuchon],x0,y0+luuchon,YELLOW);
			Write(st[chon],x0,y0+chon,CYAN);
			break;
		case 80://phim xuong
			luuchon=chon;
			chon++;
			if(chon==sodong) chon=0;
			Write(st[luuchon],x0,y0+luuchon,YELLOW);
			Write(st[chon],x0,y0+chon,CYAN);
			break;
		case 13: //phim ENTER
		ok=TRUE; break;
	}
	if (ok==TRUE) //Neu phim ENTER duoc nhan
	{
	  switch (chon)
		{
		 case 0:
			Baitap1();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 1:
			Baitap2();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 2:
			Baitap3();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 3:
			Baitap4();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 4:
			Baitap5();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 5:
			Baitap6();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 6:
			Baitap7();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 7: exit(0);
		}
	  ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
	}
  }
  while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}
