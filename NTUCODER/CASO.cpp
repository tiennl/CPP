#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll coun[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,num,m=0,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		m=max(m,num);
		coun[num]++;
	}	
	for (int i=0;i<=m;i++)
		if (coun[i]>1) res+=(coun[i]*(coun[i]-1)/2);
	cout<<res;
	return 0;
}
