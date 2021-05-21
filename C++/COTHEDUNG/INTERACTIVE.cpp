// https://codeforces.com/contest/1167/problem/B

#include <bits/stdc++.h>
int x[100],a[100],d[10000];
using namespace std;
bool kt=false;
void init(int x[],int m, int n, int p, int q){
	if (!kt){
	if (x[1]*x[2]==m && x[2]*x[3]==n && x[4]*x[5]==p && x[5]*x[6]==q){
		cout<<"! ";
		for (int i=1;i<=6;i++) cout<<x[i]<<" ";
		kt=true;
	}
	}
}
void hvi(int d[], int x[], int i, int m, int n, int p, int q){
	for (int j=1;j<=6;j++)
		if (d[a[j]]==0){
			x[i]=a[j];
			d[a[j]]=1;
			if (i==6) init(x,m,n,p,q);
			else hvi(d,x,i+1,m,n,p,q);
			d[a[j]]=0;
		}
}
int main(){
	int m,n,p,q;
	a[1]=4;
	a[2]=8;
	a[3]=15;
	a[4]=16;
	a[5]=23;
	a[6]=42;
	cout<<"? 1 2"<<endl;
	cin>>m;
	fflush(stdout);
	cout<<"? 2 3"<<endl;
	cin>>n;
	fflush(stdout);
	cout<<"? 4 5"<<endl;
	cin>>p;
	fflush(stdout);
	cout<<"? 5 6"<<endl;
	cin>>q;	
	fflush(stdout);
	hvi(d,x,1,m,n,p,q);
	return 0;
}
