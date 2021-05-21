#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005 
ll a[N],b[N]={0};
int main(){
	FIO
	ll n,q,l,r,x;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	while (q--){
		cin>>l>>r>>x;
		b[l]+=x;
		b[r+1]-=x;
	}
	ll d=0;
	for (int i=1;i<=n;i++){
		d+=b[i];
		a[i]+=d;
	}
	ll g=0,y=0,red=0;
	for (int i=1;i<=n;i++)
		if (a[i]%3==0) g++;
		else if (a[i]%3==1) y++;
		else red++;
	cout<<g<<" "<<y<<" "<<red;
	return 0;
}
