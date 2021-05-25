#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

map <ll,ll> a;

int main(){
	FIO
	ll n,num,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		a[num]++;
	}
	for (int i=10102010;i<=10109999;i++)
		if (a[i]>0 && a[i]<=5) res+=100;
		else if (a[i]>5) res+=100+a[i]-5;
	cout<<res;
	return 0;
}
