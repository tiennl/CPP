#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

stack <ll> s;

int main(){
	FIO
	ll n,num,res=1,mod=1e9+7;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		while (!s.empty() && num>s.top()){
			res=(res*num)%mod;
			s.pop();
		}
		s.push(num);
	}
	cout<<res;
	return 0;
}
