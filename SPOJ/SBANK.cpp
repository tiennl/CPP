#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define pb push_back 
#define N 1000005

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll n;
		vector <string> v;
		std::tr1::unordered_map<string,ll> m;
		std::tr1::unordered_map<string,bool> mp;
		cin>>n;
		cin.ignore();
		while (n--){
			string s;
			getline(cin,s);
			v.pb(s);
			m[s]++;
			mp[s]=false;
		}
		sort(v.begin(),v.end());
		for (auto it=v.begin();it!=v.end();it++)
			if (!mp[*it]){
				cout<<*it<<" "<<m[*it]<<endl;
				mp[*it]=true;
			}
		cout<<endl;
	}
	return 0;
}
