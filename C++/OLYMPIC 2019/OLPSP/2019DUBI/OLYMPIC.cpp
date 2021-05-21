#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define db double 
#define N 1000005

struct st{
	string name;
	db x,y;
};

int n;
int x[100],d[100];
db res=0;
st a[100];

db dis(st a, st b){
	db c1,c2,r=0;
	c1=(a.x-b.x)*(a.x-b.x);
	c2=(a.y-b.y)*(a.y-b.y);
	r=sqrt(c1+c2);
	return r;
}

void permu(ll i, ll n, db &res){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n){
				db r=0;
				for (int k=1;k<=n;k+=2) 
					r+=dis(a[x[k]],a[x[k+1]]);
				res=min(res,r);
			}
			else permu(i+1,n,res);
			d[j]=0;
		}
}

int main(){
	FIO
	ll n;
	while (cin>>n){
		res=1e9;
		if (n==0) return 0;
		n*=2;
		for (int i=1;i<=n;i++) 
			cin>>a[i].name>>a[i].x>>a[i].y;
		permu(1,n,res);
		cout<<fixed<<setprecision(2)<<res<<endl;
	}	
	return 0;
}



