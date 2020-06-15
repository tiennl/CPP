#include "windows.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <algorithm>
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

ll n=0,m=0,a[1000000],maxx[1000000],sum[1000000],num[1000000],sl[1000000],pas[500][500];

void Init_arr(ll &n, ll a[])
{
	cout<<"\nNhap n = "; 
	cin>>n;
	cout<<"\nNhap day: ";
	for (ll i=0;i<n;i++) cin>>a[i];
}


void Init_2arr(ll &m, ll &n, ll a[])
{
	cout<<"\nNhap m = "; 
	cin>>m;
	cout<<"\nNhap n = ";
	cin>>n;
	cout<<"\nNhap 2 day: ";
	for (ll i=0;i<m+n;i++) cin>>a[i];
}

void Init_n(ll &n)
{
	cout<<endl<<"Nhap n = "; 
	cin>>n;
}

ll MaxElement(ll n, ll a[]){
	ll res=a[0];
	for (ll i=1;i<n;i++)
		if (a[i]>res) res=a[i];
	return res;
}

ll CountDifferentElement(ll n, ll a[]){
	ll res=1;
	if (n==0) return 0;
	sort(a,a+n);
	for (int i=1;i<n;i++) 
		if (a[i]!=a[i-1]) res++;
	return res;
}

ll MaxLengthIncreaseArray(ll n, ll a[]){
	ll res=0;
	if (n==0) return 0;
  	maxx[0]=1;
	for (int i=1;i<n;i++) {
		if (a[i]>=a[i-1]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=1;
		if (maxx[i]>res) res=maxx[i];
	}
	return res;
}

bool SuperIncreaseArray(ll n, ll a[]){

  	if (n<2) return false;
	sum[0]=a[0];
	for (int i=1;i<n;i++){
		sum[i]=sum[i-1]+a[i];
		if (i>0 && a[i]<sum[i-1]) 
			return false;
	}
	return true;
}

bool Symability(ll n, ll a[]){
	ll chan=0,le=0,k=0,num;
	sort(a,a+n);
	num=a[0];
	sl[0]=1;
	k=0;
	for (int i=1;i<n;i++)
		if (a[i]==num) sl[k]++;
		else{
			num=a[i];
			k++;
			sl[k]=1;
		}
	k++;
	for (int i=0;i<k;i++)
		if (sl[i]%2==0) chan++;
		else le++;
	if ((n%2==0 && le>0) || (n%2==1 && le>1)) return false;
	else return true;
}

void PascalTriangle(ll &n){
	pas[1][1]=pas[2][1]=pas[2][2]=1;
	if (n>=1) cout<<1<<endl;
	if (n>=1) cout<<1<<" "<<1<<endl;
	for (int i=3;i<=n+1;i++){
		for (int j=1;j<=i;j++){
			pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
			cout<<pas[i][j]<<" ";
		}
		cout<<endl;
	}
}

ll MaxLengthFibonacci(ll &n, ll a[]){
	ll res=0;
	maxx[1]=2;
	for (int i=2;i<n;i++) {
		if (a[i]==a[i-1]+a[i-2]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=2;
		res=max(res,maxx[i]);
	}
	if (res>2) return res;
	return -1;
}

void Baitap1()
{
 	system("cls");
  	Init_arr(n,a);
  	cout<<"\nSo lon nhat trong mang: ";
	cout<<MaxElement(n,a);
  	getch();
}

void Baitap2()
{
  	system("cls");
  	Init_2arr(m,n,a);
  	sort(a,a+m+n);
  	cout<<"\nDay da sap xep:\n";
	cout<<"\n"<<m+n<<"\n\n";
	for (int i=0;i<m+n;i++) cout<<a[i]<<" ";
  	getch();
}

void Baitap3()
{
  	system("cls");
  	Init_arr(n,a);
  	cout<<"\nDo dai day con tang dai nhat: ";
  	cout<<MaxLengthIncreaseArray(n,a);
  	getch();
}

void Baitap4()
{
  	system("cls");
  	ll res=1;
  	Init_arr(n,a);
  	cout<<"\nSo luong phan tu khac nhau trong day: ";
	cout<<CountDifferentElement(n,a);
  	getch();
}

void Baitap5()
{
  	system("cls");
  	Init_arr(n,a);
  	if (SuperIncreaseArray(n,a)) cout<<"\nTRUE";
  	else cout<<"\nFALSE";
  	getch();    
}

void Baitap6()
{
  	system("cls");
	Init_arr(n,a);
	if (Symability(n,a)) cout<<"\nTRUE";
  	else cout<<"\nFALSE";
  	getch();    
}

void Baitap7()
{
  	system("cls");
	Init_n(n);
	PascalTriangle(n);
  	getch();    
}

void Baitap8()
{
  	system("cls");
	Init_arr(n,a);
	cout<<"\n"<<MaxLengthFibonacci(n,a);
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
  	Khung(x0-2,y0-1,x0+52,y0+n);
  	for(ll i=0;i<n;i++)
	 	if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 	else Write(s[i],x0,y0+i,YELLOW);
  	//Write("Copyright (c) 2016 by Pham Anh Phuong.",x0-4,y0+n+5,10);
}

main()
{
  	char ch,*st[20];
  	system("cls");
  	st[0]="ARRMAX So lon nhat trong mang";
  	st[1]="MERGEARR Sap xep hai mang theo thu tu tang dan";
  	st[2]="DAYTANG Do dai day con tang dan dai nhat";
  	st[3]="SETNUM So luong phan tu khac nhau trong day";
  	st[4]="SUPASCEN Kiem tra day sieu tang";
  	st[5]="SYMABILITY Kiem tra day kha doi xung";
  	st[6]="PASCAL Tam giac Pascal";
  	st[7]="FSEQ Do dai day con co tinh chat cua day Fibonacci";
  	st[8]="<ESC> Ket thuc chuong trinh!";
  	ll x0=10,y0=10,chon=0,luuchon,sodong=9,ok=FALSE;
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
