#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000
ll b[N],c[N];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,d=0,res;
	cin>>n;
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n;i++) cin>>c[i];
	sort(b,b+n);
	sort(c,c+n);
	res=abs(b[0]+c[0]);
	ll i=0,j=n-1;
	while (i<n && j>=0){
		if (b[i]+c[j]==0){
			cout<<0;
			return 0;
		}
		res=min(res,abs(b[i]+c[j]));
		if (b[i]+c[j]<0) i++;
		else j--;
	}
	cout<<res;
	return 0;
}
