#include <bits/stdc++.h>
long long x[1000000],y[1000000],z[1000000];
using namespace std;
long long tv(long long a[], long long n){
	long long res=0;
	sort(a,a+n);
	if (n%2!=0) return a[n/2];
	return (a[n/2-1]+a[n/2])/2;
}
int main(){
	unsigned long long n,x0,y0,z0,x1,y1,z1,res=0,resx=0,resy=0,resz=0;
	cin>>n>>x0>>y0>>z0;
	for (int i=0;i<n;i++){
		cin>>x1>>y1>>z1;
		res+=(abs(x1-x0)+abs(y1-y0)+abs(z1-z0));
		x[i]=x1;
		y[i]=y1;
		z[i]=z1;
	}
	resx=tv(x,n);
	resy=tv(y,n);
	resz=tv(z,n);
	for (int i=0;i<n;i++)
		res+=(abs(resx-x[i])+abs(resy-y[i])+abs(resz-z[i]));
	cout<<res<<endl;
	cout<<resx<<" "<<resy<<" "<<resz;
	return 0;
}
