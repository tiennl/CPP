#include "windows.h"
#include <iostream>
#include <vector>
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
#define ull unsigned long long 
#define pb push_back

string a,b;

int string_to_num(char c){
	return c-'0';
}

char num_to_string(int n){
	return (char)(n+48);
}

void chuan_hoa(string &a, string &b){
    int l1=a.length(), l2=b.length();
    if (l1>=l2){
    	b.insert(0,l1-l2,'0');
	}
	else{
		a.insert(0,l2-l1,'0');
	}
}

string sum(string a, string b){    
	string s="";
	chuan_hoa(a,b);
	int l=a.length();
	int temp=0;
	for (int i=l-1;i>=0;i--){
		temp=string_to_num(a[i])+string_to_num(b[i])+temp;
		s.insert(0,1,num_to_string(temp%10));
		temp=temp/10;
	}
	if (temp>0){
		s.insert(0,1,num_to_string(temp));
	}
	return s;
}

string nhan_nho(char a, string b){
	string s="";
	int temp=0;
	for (int i=b.length()-1; i>=0; i--){
		temp=string_to_num(a)*string_to_num(b[i])+temp;
		s.insert(0,1,num_to_string(temp%10));
		temp=temp/10;
	}
	if (temp>0){
		s.insert(0,1,num_to_string(temp));
	}
	return s;
}

struct num{
	int n1,n2;
};

string chia(int divisor, string number){ 
    string ans; 
    int idx=0; 
    int temp=number[idx]-'0'; 
    while (temp<divisor) 
       temp=temp*10+(number[++idx]-'0'); 
    while (number.size()>idx){ 
        ans+=(temp/divisor)+'0'; 
        temp=(temp%divisor)*10+number[++idx]-'0'; 
    } 
    if (ans.length()==0) 
        return "0"; 
    return ans; 
} 

string nhan_Bac_My(string a, string b){
	string res="";
	int l=a.length();
	string s1[l];
	for (int i=l-1; i>=0; i--){
	    s1[i]=nhan_nho(a[i],b);
	    s1[i].insert(s1[i].length(),l-i-1,'0');
	    res=sum(res,s1[i]);
	}
	return res;
}

string nhan_A_Rap(string a, string b){
	string res="";
	num t;
	int ex=0;
	vector <num> x[b.size()];
	for(int i=0;i<b.size();i++)
		for(int j=0;j<a.size();j++){
			t.n1=(b[i]-48)*(a[j]-48);
			t.n2=t.n1%10;
			t.n1=t.n1/10;
			x[i].pb(t);
		}
	for(int i=a.size()-1;i>=0;i--){
		int j=b.size()-1,k=i,coun=0;
		int s=ex;
		while(k<a.size() && j>=0){
			coun++;
			if(coun%2==1){
				s+=x[j][k].n2;
				k++;
			}
			else{
				s+=x[j][k].n1;
				j--;
			}
		}
		string temp="";
		temp.pb(s%10+48);
		res=temp+res;
		ex=s/10;
	}
	for(int i=b.size()-1;i>=0;i--){
		int j=0,k=i,coun=0;
		int s=ex;
		while(j<a.size() && k>=0){
			coun++;
			if(coun%2==1){
				s+=x[k][j].n1;
				k--;
			}
			else{
				s+=x[j][k].n2;
				j++;
			}
		}
		string temp="";
		temp.pb(s%10+48);
		res=temp+res;
		ex=s/10;
	}
	string temp="";
	if(ex>0) temp.pb(ex+48);
	res=temp+res;
	while(res[0]=='0' && res.size()>1)
	res.erase(res.begin());
	return res;
}

string nhan_Nga(string a, string b){
	string res="";
	if (string_to_num(a[a.size()-1])%2!=0) res=sum(res,b);
	while (a!="1"){
		a=chia(2,a);
		b=nhan_nho('2',b);
		if (string_to_num(a[a.size()-1])%2!=0) res=sum(res,b);
	}
	return res;
}

void Baitap0()
{
  system("cls");
  cout<<"\nNhap a = ";cin>>a;
  cout<<"\nNhap b = ";cin>>b;
  cout<<"\nTich 2 so: "<<a<<" * "<<b<<" = "<<nhan_Bac_My(a,b); 
  getch();    
}

void Baitap1()
{
  system("cls");
  cout<<"\nNhap a = ";cin>>a;
  cout<<"\nNhap b = ";cin>>b;
  cout<<"\nTich 2 so: "<<a<<" * "<<b<<" = "<<nhan_A_Rap(a,b); 
  getch();    
}

void Baitap2()
{
  system("cls");
  cout<<"\nNhap a = ";cin>>a;
  cout<<"\nNhap b = ";cin>>b;
 cout<<"\nTich 2 so: "<<a<<" * "<<b<<" = "<<nhan_Nga(a,b); 
  getch();    
}

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
void Ve_menu(int x0,int y0,int chon,int n,char *s[])
{
  system("cls");
  Khung(x0-2,y0-1,x0+35,y0+n);
  for(int i=0;i<n;i++)
	 if(i==chon) Write(s[i],x0,y0+i,CYAN);
	 else Write(s[i],x0,y0+i,YELLOW);
  Write("Copyright (c) 2019 by Pham Anh Phuong.",x0-4,y0+n+5,10);


}

main()
{
  char ch,*st[20]; 
  system("cls");
  st[0]="1. Nhan 2 so kieu Anh";
  st[1]="2. Nhan 2 so kieu A Rap";
  st[2]="3. Nhan 2 so kieu Nga";
  st[3]="<ESC> Ket thuc chuong trinh!";
  int x0=5,y0=5,chon=0,luuchon,sodong=4,ok=FALSE;
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
		 case 3: exit(0);
		}
	  ok=FALSE; 
	}
  }
  while (ch!=27);
}
