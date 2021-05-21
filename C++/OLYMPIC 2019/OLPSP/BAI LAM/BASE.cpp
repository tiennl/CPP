#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
bool check(ll a, ll b){
	ll r=a%b;
	while (a>0){
		if (a%b!=r) return false;
		a/=b;
	}
	return true;
}
int main(){
	FIO
	ll x,res=x+1;
	bool ok=0;
	cin>>x;
	for (int i=2;i<=sqrt(x);i++)
		if (check(x,i)){
			cout<<i;
			return 0;
		}
	for (int i=sqrt(x);i>0;i--)
		if ((x-i)%i==0 && x!=i && check(x,(x-i)/i) && (x-i)/i>=2){
			cout<<(x-i)/i;
			return 0;
		}
	cout<<x+1;
	return 0;
}
