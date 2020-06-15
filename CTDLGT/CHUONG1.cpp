#include "windows.h"
#include <iostream>
#include <conio.h>
#include <math.h>
typedef long long ll;
using namespace std;

#ifdef WIN32
void gotoxy(ll x, ll y)
{
 	COORD cur = {x, y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
} 
#else
void gotoxy(ll x, ll y)
{
  	printf("\033[%dG\033[%dd", x+1, y+1);
}
#endif

ll textcolor(ll Color)
{
 	HANDLE h;
 	h = GetStdHandle(STD_OUTPUT_HANDLE); 
 	return SetConsoleTextAttribute(h, Color);
}

#define CYAN 10
#define YELLOW 14

ll n=0,m=0, A[50],B[50];

void Init_a_b(ll &n, ll &m)
{
	cout<<endl<<"Nhap a = "; 
	cin>>n;
	cout<<endl<<"Nhap b = "; 
	cin>>m;
}

void Init_n(ll &n)
{
	cout<<endl<<"Nhap n = "; 
	cin>>n;
}

ll UCLN(ll n, ll m){
	ll r;
	while (m>0){
		r=n%m;
		n=m;
		m=r;
	}
	return n;
}

ll fibo(ll n){
	if (n<=2) return 1;
	else return fibo(n-1)+fibo(n-2); 
}

ll Ackermann(ll m, ll n){
	if (m==0) return n+1;
	else if (n==0) return Ackermann(m-1,1);
	else if (m>0 || n>0) return Ackermann(m-1,Ackermann(m,n-1));
	return 0;
}


bool doixung(string s,ll l,ll r){
	if (l<r)
	{
		if (s[l]!=s[r]) return 0;
		else return doixung(s,l+1,r-1);
	}
	return 1;
}


double S1(double n){
	if (n==0) return 0;
	else return n+S1(n-1); 
}

double S2(double n){
	if (n==0) return 0;
	else return 1/n+S2(n-1);
}

double S3(double n){
	if (n==0) return 0;
	else return pow(-1,n+1)*(1/n)+S3(n-1);
}

double S4(double n, double x){
	if (n==0) return 1;
	else return pow(sin(x),n)+S4(n-1,x);
}

ll Calanta(ll k, ll n){
	if (n==k || k==0) return 1;
	else return Calanta(k-1,n-1)+Calanta(k,n-1);
}

void Baitap1()
{
 	system("cls");
  	cout<<"\nNhap hai so nguyen a va b\n";
  	Init_a_b(n,m);
  	cout<<"\nUoc chung lon nhat cua 2 so la: ";
  	cout<<UCLN(n,m);
  	getch();
}

void Baitap2()
{
  	system("cls");
  	string s;
  	cout<<"\nNhap so nguyen n = ";
  	cin>>s;
  	cout<<"\nSo chu so cua n la: ";
  	cout<<s.size();
  	getch();
}

void Baitap3()
{
  	system("cls");
  	Init_n(n);
  	cout<<"\nF("<<n<<") = "<<fibo(n);
  	getch();
}

void Baitap4()
{
  	system("cls");
  	cout<<"\nA(1,2) = "<<Ackermann(1,2)<<"\n";
  	cout<<"\nNhap m = ";
  	cin>>m;
  	Init_n(n);
  	cout<<"\nA(m,n) = "<<Ackermann(m,n);
  	getch();
}

void Baitap5()
{
  	system("cls");
  	string s;
  	cout<<"\nNhap n = ";
  	cin>>s;
  	if (doixung(s,0,s.size()-1)) cout<<"\nTRUE";
	else cout<<"\nFALSE";
  	getch();    
}

void Baitap6()
{
  	system("cls");
	double n,x;
  	cout<<"\nNhap n = ";
  	cin>>n;
  	cout<<"\nNhap x = ";
  	cin>>x;
  	cout<<"\nS1 = "<<S1(n)<<"\n";	
  	cout<<"\nS2 = "<<S2(n)<<"\n";
  	cout<<"\nS3 = "<<S3(n)<<"\n";
  	cout<<"\nS4 = "<<S4(n,x)<<"\n";
  	getch();    
}

void Baitap7()
{
  	system("cls");
  	ll k;
  	Init_n(n);
  	cout<<"\nNhap k = ";
  	cin>>k;
  	cout<<"\nC(k,n) = "<<Calanta(k,n);
  	getch();    
}

void Baitap8()
{
  	system("cls");
	string s;
  	cout<<"\nNhap n = ";
  	cin>>s;
  	cout<<"\nSo sao nguoc cua n la: ";
  	for (ll i=s.size()-1;i>=0;i--) cout<<s[i];
  	getch();    
}

void Write(char *s, ll x, ll y, ll color)
{
  	textcolor(color);
  	gotoxy(x,y); cout<<s;
  	textcolor(15);
}

void Khung(ll x1, ll y1, ll x2, ll y2)
{ 
	ll x,y;
  	gotoxy(x1,y1); cout<<"É";
  	gotoxy(x2,y1); cout<<"»";
  	gotoxy(x1,y2); cout<<"È";
  	gotoxy(x2,y2); cout<<"¼";
  	for(x=x1+1;x<x2;x++){
		gotoxy(x,y1); cout<<"Í";
		gotoxy(x,y2); cout<<"Í";
	}
  	for(y=y1+1;y<y2;y++){
		gotoxy(x1,y); cout<<"º";
		gotoxy(x2,y); cout<<"º";
	}
}
void Ve_menu(ll x0, ll y0, ll chon, ll n, char *s[])
{
  	system("cls");
  	Khung(x0-2,y0-1,x0+30,y0+n);
  	for(ll i=0;i<n;i++)
	 	if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 	else Write(s[i],x0,y0+i,YELLOW);
  	//Write("Copyright (c) 2016 by Pham Anh Phuong.",x0-4,y0+n+5,10);
}

main()
{
  	char ch,*st[20];
  	system("cls");
  	st[0]="Bai 1 Tim UCLN";
  	st[1]="Bai 2 Dem so chu so";
  	st[2]="Bai 3 Tim so Fibonacci";
  	st[3]="Bai 4 Tinh Ackermann";
  	st[4]="Bai 5 Kiem tra so doi xung";
  	st[5]="Bai 6 Tinh gia tri bieu thuc";
  	st[6]="Bai 7 Tinh to hop";
  	st[7]="Bai 8 So dao nguoc";
  	st[8]="<ESC> Ket thuc chuong trinh!";
  	ll x0=25,y0=10,chon=0,luuchon,sodong=9,ok=FALSE;
  	Ve_menu(x0,y0,chon,sodong,st);
  	do{
  		ch=getch(); //Nhan mot phim
  		switch (ch){
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
				ok=TRUE; 
				break;
		}
		if (ok==TRUE){ //Neu phim ENTER duoc nhan
	  		switch (chon){
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
				case 7:
					Baitap8();
					Ve_menu(x0,y0,chon,sodong,st);
					break;
		 		case 8: exit(0);
			}
	  	ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
		}
  	}
  	while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}
