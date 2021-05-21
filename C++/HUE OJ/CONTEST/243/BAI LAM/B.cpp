#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[10000000],b[10000000],pos[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=0;i<n;i++) pos[i]=0;
	sort(a,a+n,greater<ll>());
	for (int i=0;i<n;i++)
		if (pos[a[i]]==0) pos[a[i]]=i+1;
	for (int i=0;i<n;i++)
		cout<<pos[b[i]]<<endl;
	return 0;
}
