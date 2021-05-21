#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
ll a[500]={0}; 
ll count5(ll n){
    ll count=0;
    double k=log(n)/log(5);
    for (int i=1;i<=k;i++)
        count+=n/pow(5,i);
    return count; 
}
ll count2(ll n){
    ll count=0;
    double k=log(n)/log(2);
    for (int i=1;i<=k;i++)
        count+=n/pow(2,i);
    return count; 
}
int main(){
	FIO
	ll n,res=0,c2=0,c5=0;
	string s;
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++) a[s[i]]++;
	c5=count5(n);
	c2=count2(n);
	for (int i='A';i<='Z';i++)
		if (a[i]>0) c5-=count5(a[i]),c2-=count2(a[i]);
	for (int i='a';i<='z';i++)
		if (a[i]>0) c5-=count5(a[i]),c2-=count2(a[i]);
	res=min(c5,c2);
	if (res<0) cout<<0;
	else cout<<res;
	return 0;
}
