#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pb push_back
#define N 100005

ll a[N];
vector <ll> vt;

int main(){
	FIO
	ll n;
	cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
   	for (int i=0;i<n;i++)
   		if (vt.size()==0 || vt[vt.size()-1]<=a[i]) vt.pb(a[i]);
		else{
			ll l=0,r=vt.size()-1,p;
			while (l<r){
				p=(l+r)/2;
				if (vt[p]<a[i]) l=p+1;
				else r=p-1;   
			}
			if (vt[p]>a[i] && p>=0 && p<vt.size()) vt[p]=a[i];
		} 
	cout<<n-vt.size();
	return 0;
}
