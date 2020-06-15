#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll n,res=0;
	cin>>n;
	map <ll,int> mp;
	while (n--){
		ll num;
		cin>>num;
		mp[num]++;
	}
	for (map<ll,int>::iterator it=mp.begin();it!=mp.end();it++){
		if (it->second<5) res+=100;
		else res+=100+(it->second-5);
	}
	cout<<res;
	return 0;
}
