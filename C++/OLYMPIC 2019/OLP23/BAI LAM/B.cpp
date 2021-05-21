#include <bits/stdc++.h>
long long x[10000000],y[10000000],z[10000000];
using namespace std;
long long tv(long long a[], long long n){
	long long restv=0;
	sort(a+1,a+n+1);
//	if (n%2!=0) restv=a[n/2];
//	else restv=(a[(n/2)-1]+a[n/2])/2;
	restv=a[(n+1)/2];
	return restv;
}
int main(){
	long long n,x0,y0,z0,x1,y1,z1,resx=0,resy=0,resz=0;
	unsigned long long res=0;
	cin>>n;
	for (int i=0;i<=n;i++){
		cin>>x1>>y1>>z1;
		x[i]=x1;
		y[i]=y1;
		z[i]=z1;
	}
	resx=tv(x,n);
	resy=tv(y,n);
	resz=tv(z,n);
	for (int i=1;i<=n;i++){
		res+=(abs(x[i]-x[0])+abs(y[i]-y[0])+abs(z[i]-z[0]));
		res+=(abs(resx-x[i])+abs(resy-y[i])+abs(resz-z[i]));
	}
	cout<<res<<endl;
	cout<<resx<<" "<<resy<<" "<<resz;
	return 0;
}
