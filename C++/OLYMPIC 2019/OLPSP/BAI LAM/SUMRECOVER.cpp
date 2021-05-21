#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005 
ll a[N],s[N]={0};
int main(){
	FIO
	ll n,m,res=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	cin>>m;
	while (m--){
		ll b,x,y;
		cin>>b>>x>>y;
		if (b==0) a[x]=y;
		else{
			res=0;
			for (int i=x;i<=y;i++) res+=a[i];
			cout<<res<<endl;
		}
	}
	return 0;
}
