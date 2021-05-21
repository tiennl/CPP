#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005
ll a[N],b[N]={0}; 
int main(){
	FIO
	ll n,res=0,mi,ma;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		set <ll> s;
		mi=a[i];
		ma=a[i];
		for (int j=i;j<n;j++){
			s.insert(a[j]);
			mi=min(mi,a[j]);
			ma=max(ma,a[j]);
			if (s.size()!=j-i+1) break;
			if (ma-mi+1==s.size()) res++; 
		}
	}
	cout<<res;
	return 0;
}
