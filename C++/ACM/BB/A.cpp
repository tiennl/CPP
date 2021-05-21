#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define db double 
#define N 2005

struct point{
	db x,y;
};

point arr[N],nxt[N];

double Striangle(point A, point B, point C){
	return abs((B.x*A.y-A.x*B.y) + (C.x*B.y-B.x*C.y) + (A.x*C.y-C.x*A.y))/2;
}

int main(){
	FIO
	ll n;
	point a,b,c;
	db res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			ll p=(i+j)/2;
			res=max(res,Striangle(arr[i],arr[j],arr[p]));
			p=(i+j)/2+1;
			res=max(res,Striangle(arr[i],arr[j],arr[p]));
			p=j+(n-1-j)/2;
			res=max(res,Striangle(arr[i],arr[j],arr[p]));
			p=j+(n-1-j)/2+1;
			res=max(res,Striangle(arr[i],arr[j],arr[p]));
		}
	cout<<fixed<<setprecision(1)<<res;
	return 0;
}












