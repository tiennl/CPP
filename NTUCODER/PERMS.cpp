#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll x[100];
bool d[100];
ll n;
ll gt(ll n){
	ll r=1;
	for (int i=2;i<=n;i++) r*=i;
	return r;
}
void print(){
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<endl;
}
void hvi(ll i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n) print();
			else hvi(i+1);
			d[j]=0;
		}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	cout<<gt(n)<<endl;
	hvi(1);
	return 0;
}
