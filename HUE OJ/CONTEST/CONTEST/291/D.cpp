#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

double dis(ll x, ll y, ll x1, ll y1){
	return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

int main(){
	FIO
	ll x,y,x1,y1,x2,y2;
	double res;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	res=dis(x,y,x1,y1);
	for (int i=x1;i<=x2;i++){
		res=min(res,dis(x,y,i,y1));
		res=min(res,dis(x,y,i,y2));
	}
	for (int i=y1;i<=y2;i++){
		res=min(res,dis(x,y,x1,i));
		res=min(res,dis(x,y,x2,i));
	}
	cout<<fixed<<setprecision(1)<<res;
	return 0;
}
