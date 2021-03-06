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

void Baitap0()
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

int UCLN(int a,int b)
{
	if(a==b) return a;
	else if(a>b) return UCLN(a-b,b);
	     else return UCLN(a,b-a);
}
void Baitap1()
{
  system("cls");
  int a,b;
  cout<<endl<<"Tim UCLN cua 2 so a,b";
  cout<<endl<<"a = "; cin>>a;
  cout<<endl<<"b = "; cin>>b;
  cout<<endl<<"UCLN(a,b) = "<<UCLN(a,b); 
  
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
void Baitap2()
{
  system("cls");
  cout<<endl<<"Tinh tong mang";
  int n, a[100];
  Nhap(n,a);
  cout<<endl<<"Tong mang = "<<Tong(n,a);  
  getch();    
}

int Fibo1(int n)
{
	if(n==1||n==2) return 1;
	else return Fibo1(n-1) + Fibo1(n-2);
}

void Baitap3()
{
  system("cls");
  cout<<endl<<"Tinh so hang thu n cua day Fibonaci";
  int n;
  cout<<endl<<"Nhap n = "; cin>>n;
  cout<<"So Fibonaci thu "<<n<<" la:"<<Fibo1(n);
  getch();  	
}

int S(int n)
{
	if(n==0) return 0;
	else return n%10 + S(n/10);
}
void Baitap4()
{
  system("cls");
  cout<<endl<<"Tinh tong cac chu so cua n";
  int n;
  cout<<endl<<"Nhap n = "; cin>>n;
  cout<<"Tong la:"<<S(n);
  getch();  	
}
int Fibo2(int n)
{
	int a[100];
	a[1] = a[2] = 1;
	int i = 3;
	while(i<=n)
	{
		a[i] = a[i-1] + a[i-2];
		i++;
	}
	return a[n];
}
void Baitap5()
{
  system("cls");
   int n;
  cout<<endl<<"Nhap n = "; cin>>n;
  cout<<"So hang Fibo thu n la:"<<Fibo2(n);
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
  gotoxy(x1,y1); cout<<"�";
  gotoxy(x2,y1); cout<<"�";
  gotoxy(x1,y2); cout<<"�";
  gotoxy(x2,y2); cout<<"�";
  for(x=x1+1;x<x2;x++)
	 {
		gotoxy(x,y1); cout<<"�";
		gotoxy(x,y2); cout<<"�";
	 }
  for(y=y1+1;y<y2;y++)
	 {
		gotoxy(x1,y); cout<<"�";
		gotoxy(x2,y); cout<<"�";
	 }
}
/*Tao ra menu tai toa do (x0,y0) voi n dong luu trong bien s
chon: dong menu hien thoi (khac mau voi cac dong khac) */
void Ve_menu(int x0,int y0,int chon,int n,char *s[])
{
  system("cls");
  Khung(x0-2,y0-1,x0+35,y0+n);
  for(int i=0;i<n;i++)
	 if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 else Write(s[i],x0,y0+i,YELLOW);
  Write("Copyright (c) 2019 by Pham Anh Phuong.",x0-4,y0+n+5,10);
  Write("Danh sach nhom:",x0+40,y0,14);
  Write("1. Pham Anh Phuong",x0+40,y0+1,14);
  Write("2. Nguyen Van X",x0+40,y0+2,14);
  Write("3. Nguyen Van Y",x0+40,y0+3,14);

}

main()
{
  char ch,*st[20]; //Ghi cac dong menu
  system("cls");
  st[0]="1. Tinh dien tich tam giac";
  st[1]="2. Tim UCLN";
  st[2]="3. Tinh tong";
  st[3]="3. Day Fibonaci 1";
  st[4]="5. Tong cac chu so cua n";
  st[5]="6. Day Fibonacci 2 khong de quy";
  st[6]="<ESC> Ket thuc chuong trinh!";
  int x0=5,y0=5,chon=0,luuchon,sodong=7,ok=FALSE;
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
			Baitap0();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 1:
			Baitap1();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 2:
			Baitap2();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 3:
			Baitap3();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 4:
			Baitap4();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 5:
			Baitap5();
			Ve_menu(x0,y0,chon,sodong,st);
			break;
		 case 6: exit(0);
		}
	  ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
	}
  }
  while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}
