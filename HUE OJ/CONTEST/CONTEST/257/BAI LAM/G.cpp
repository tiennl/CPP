#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
ll a[100];
int main(){
	FIO
	ll n,s,r,num,res=0;
	cin>>n>>s>>r;
	for (int i=1;i<=n;i++) a[i]=1;
	while (s--){
		cin>>num;
		a[num]--;
	}
	while (r--){
		cin>>num;
		a[num]++;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==0){
			if (a[i-1]==2) a[i]=1,a[i-1]=1;
			else if (a[i+1]==2) a[i]=1,a[i+1]=1;
		}
	for (int i=1;i<=n;i++)
		if (a[i]==0) res++;
	cout<<res;
	return 0;
}
