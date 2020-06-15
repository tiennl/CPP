#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define pb push_back 
#define N 10005

ll n;
string s;
vector <string> res;
map <string,ll> mp;
ll x[N],d[N];

void pf(){
	string st="";
	for (int j=1;j<=n;j++) st+=s[x[j]-1]; 
	if (mp[st]==0) res.pb(st),mp[st]++;
}

void per(ll i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n) pf();
			else per(i+1);
			d[j]=0;
		}
}

int main(){
	FIO
	cin>>s;
	n=s.size();
	per(1);
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for (int i=0;i<res.size();i++) cout<<res[i]<<endl;
	return 0;
}
