#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

map<string,ll> a;

int main(){
	FIO
	ll n,c;
	string s1,s2;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s1>>s2>>c;
		a[s1]+=c;
		a[s2]+=c;
	}
	map<string,ll>::iterator i;
    for (i=a.begin();i!=a.end();i++){
        cout<<i->first<<" "<< i->second<<endl;
    }
	return 0;
}
