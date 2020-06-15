#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005

using namespace std;

ll a[N],c[N],s[N];

struct ex{
	ll x,y;
};

ex b[N];

ll CMP(ex &a, ex &b){
	if (a.x!=b.x) return a.x<b.x;
	else return a.y>b.y;
}

int main(){
	ll n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<m;i++) cin>>b[i].x>>b[i].y;
	sort(b,b+m,CMP);
	for (int i=0;i<m;i++) c[i]=b[i].x;
	s[0]=b[0].y;
	for (int i=1;i<m;i++) s[i]=s[i-1]+b[i].y;
	for (int i=0;i<n;i++){
		ll p=upper_bound(c+0,c+m,a[i])-c;
		if (a[i]>=c[p-1] && p-1>=0 && p-1<m) cout<<s[p-1]<<" ";
		else cout<<0<<" ";
	}
 	return 0;
}

