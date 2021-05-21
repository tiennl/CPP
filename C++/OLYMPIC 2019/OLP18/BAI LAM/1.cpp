#include <bits/stdc++.h>
long long x[1000];
long long d=0;
using namespace std;
void gn(long long x[],long long n, long long &d){
	long long s=0;
	for (int i=1;i<=n;i++) s+=x[i];
	if (s%3==0){
		d++;
		for (int i=1;i<=n;i++) cout<<x[i]<<" ";
		cout<<endl;
	}
}
void hvi(long long x[],long long n, long long i){
	for (int j=1;j<=3;j++){
		x[i]=j;
		if (i==n) gn(x,n,d);
		else hvi(x,n,i+1);
	}
}
int main(){
	long long n;
	cin>>n;
	d=0;
	hvi(x,n,1);
	cout<<d;
	return 0;
}
