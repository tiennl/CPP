#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ifstream fi ("BORECOLE.INP");
	ofstream fo ("BORECOLE.OUT");
	ll n,r,m;
	fi>>n>>r>>m;
	for (int i=0;i<n;i++) fi>>a[i];
	while (m--){
		ll mi=a[0],pmi=0,ma=0,pma=0;
		for (int i=1;i<n;i++)
			if (a[i]<mi && a[i]>0){
				mi=a[i];
				pmi=i;
			}
		for (int i=0;i<n;i++){
			if (i>=pmi-r || i<=pmi+r && a[i]>0) a[i]++;
			if (a[i]>ma){
				ma=a[i];
				pma=i;
			}
		}
		for (int i=pma-r;i<=pma+r;i++) a[i]=-1;
	}	
	sort(a,a+n,greater<ll>());
	if (a[0]==-1) fo<<0;
	else fo<<a[0];
	fi.close();
	fo.close();
}
