#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,m,k,p,h,maxx=0;
	cin>>n>>m>>k>>p;
	for (int i=0;i<n;i++){
		cin>>a[i]>>h;
		maxx=max(maxx,a[i]);
		maxx=max(maxx,h);
		a[i]+=h*m;
	}
	k*=m;
	while (k--){
		sort(a,a+n,greater<long long>());
		a[0]-=p;
	} 
	sort(a,a+n,greater<long long>());
	if (a[0]>=0) cout<<a[0];
	else cout<<maxx;
	return 0;
}
