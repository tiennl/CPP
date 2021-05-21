#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10005
int a[N]={1,5,10,50,100,500};
int b[N];
int main(){
	FIO
	ll x,res=0,d=5;
	for (int i=0;i<6;i++) cin>>b[a[i]];
	cin>>x;
	while (x>0 && d>=0){
		int k=x/a[d];
		if (k<=b[a[d]]){
			x-=k*a[d];
			if (k>0) res+=k;
		}
		else{
			k=b[a[d]];
			x-=k*a[d];
			if (k>0) res+=k;
		}
		d--;
	}
	if (x==0) cout<<res;
	else cout<<-1;
	return 0;
}
