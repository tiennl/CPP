#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 50

ll a[N],b[N];

int main(){
	FIO
	ll n,res=1,ok=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	for (int i=0;i<n;i++){
		ll coun=0;
		for (int j=i;j<n;j++) 
			if (a[j]<=b[i]) coun++;
		if (coun>0) res*=coun,ok=1;
	}
	if (ok==0) cout<<0;
	else cout<<res;
	return 0;
}
