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
#define ll long long

ll count=0;

void Bin(ll n){
	if (n>0){
		Bin(n/2);
		cout<<n%2;
	}
}

ll digit(ll n){
	if (n>=0 && n<10) return 1;
	else return 1+digit(n/10);
}

ll fibo(ll n){
	if (n==1 || n==2) return 1;
	else return fibo(n-1)+fibo(n-2);
}

void HaNoiTown(ll n, char A, char B, char C){
	if (n==1)
		cout<<"Chuyen dia tu coc "<<A<<" sang coc "<<C<<endl;
	else{
		HaNoiTown(n-1,A,C,B);
		HaNoiTown(1,A,B,C);
		HaNoiTown(n-1,B,A,C);
	}
}

void Print(ll n, ll x[]){
	for (int i=1;i<=n;i++) cout<<x[i]<<" ";
	cout<<endl;
}

void Try(ll i, ll n, ll x[], bool b[]){
	int j;
	for (int j=1;j<=n;j++)
		if (b[j]){
			x[i]=j;
			b[j]=false;
			if (i==n) Print(n,x);
			else Try(i+1,n,x,b);
			b[j]=true;
		}
}

void outputXepHau(ll n, ll x[]){ 
  	count++; 
  	cout<<count; 
  	for(int i=1;i<=n;i++) cout<<x[i]<<" "; 
  	cout<<endl;
} 

void TryXepHau(ll i, ll n, ll x[], ll a[], ll b[], ll c[]){ 
  	int j; 
   	for(j=1;j<=n;j++) 
     	if  (a[j] && b[i+j] && c[i-j+n]){  
         	x[i]=j; 
         	a[j]=false; 
			b[i+j]=false; 
			c[i-j+n]=false; 
         	if (i==n) outputXepHau(n,x);
  			else TryXepHau(i+1,n,x,a,b,c); 
         	a[j]=true; 
			b[i+j]=true; 
			c[i-j+n]=true; 
      	} 
} 

void Baitap0()
{
  	system("cls");
  	ll n;
	cout<<"Nhap n = ";
	cin>>n;
	Bin(n); 
  	getch();    
}

void Baitap1()
{
  	system("cls");
 	ll n;
 	cout<<"Nhap n = ";
	cin>>n;
	cout<<digit(n); 
  	getch();    
}

void Baitap2()
{
  	system("cls");
   	ll n;
   	cout<<"Nhap n = ";
   	cin>>n;
   	cout<<fibo(n);
  	getch();    
}

void Baitap3()
{
  	system("cls");
  	ll n;
	char A='A',B='B',C='C';
	cout<<"Nhap so dia n = ";
	cin>>n;
	HaNoiTown(n,A,B,C);	
  	getch();  	
}

void Baitap4()
{
  	system("cls");
  	ll n;
  	ll x[100];
	bool b[100];
 	cout<<"Nhap n = ";
	cin>>n;
	for (int i=1;i<=n;i++) b[i]=true;
	Try(1,n,x,b);
  	getch();  	
}

void Baitap5()
{
  	system("cls");
  	ll n;
	ll x[10000]; 
	ll a[10000]; 
	ll b[2*10000+1]; 
	ll c[2*10000];
  	cout<<"Nhap n = ";
  	cin>>n;
  	for(int i=1;i<=n;i++) a[i]=true; 
  	for(int i=2;i<=2*n;i++) b[i]=true; 
  	for(int i=1;i<=2*n-1;i++) c[i]=true; 
  	TryXepHau(1,n,x,a,b,c);
  	getch();  	
}

void Write(char *s,int x,int y, int color)
{
  	textcolor(color);
  	gotoxy(x,y); cout<<s;
  	textcolor(15);
}

void Khung(int x1,int y1,int x2,int y2)
{ 
	int x,y;
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

void Ve_menu(int x0,int y0,int chon,int n,char *s[])
{
  	system("cls");
  	Khung(x0-2,y0-1,x0+35,y0+n);
  	for(int i=0;i<n;i++)
	 	if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 	else Write(s[i],x0,y0+i,YELLOW);
  	Write("Copyright (c) 2019 by Pham Anh Phuong.",x0-4,y0+n+5,10);
  	Write("Danh sach nhom:",x0+40,y0,14);
  	Write("1. Ngo Le Thuy Tien",x0+40,y0+1,14);
}

main()
{
  	char ch,*st[20];
  	system("cls");
  	st[0]="1. Chuyen thap phan sang nhi phan";
  	st[1]="2. Dem so chu so cua mot so";
  	st[2]="3. Tinh so Fibonacci";
  	st[3]="4. Thap Ha Noi";
  	st[4]="5. Liet ke hoan vi";
  	st[5]="6. Xep hau";
  	st[6]="<ESC> Ket thuc chuong trinh!";
  	int x0=5,y0=5,chon=0,luuchon,sodong=7,ok=FALSE;
  	Ve_menu(x0,y0,chon,sodong,st);
  	do
  	{
	  	ch=getch(); 
	  	switch (ch)
		{
			case 72: 
				luuchon=chon;
				chon--;
				if(chon<0) chon=sodong-1;
				Write(st[luuchon],x0,y0+luuchon,YELLOW);
				Write(st[chon],x0,y0+chon,CYAN);
				break;
			case 80:
				luuchon=chon;
				chon++;
				if(chon==sodong) chon=0;
				Write(st[luuchon],x0,y0+luuchon,YELLOW);
				Write(st[chon],x0,y0+chon,CYAN);
				break;
			case 13:
			ok=TRUE; break;
		}
		if (ok==TRUE) 
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
		  ok=FALSE; 
		}
  	}
  	while (ch!=27);
}
