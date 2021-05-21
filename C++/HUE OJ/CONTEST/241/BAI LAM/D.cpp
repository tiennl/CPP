#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll l[10000000],r[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,num,x=21;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		x-=num;
	}
	l[0]=0;r[0]=13;
	for (int i=1;i<11;i++) l[i]=i-1,r[i]=13-l[i];
	for (int i=11;i<1000;i++) l[i]=13,r[i]=0;
	if (r[x]>=l[x]) cout<<"No";
	else cout<<"Yes";
	return 0;
}
