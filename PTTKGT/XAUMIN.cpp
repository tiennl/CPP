#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s,res="";
	ll k,p=0;
	cin>>k>>s;
	for (int i=0;i<s.size()-k;i++){
		string minn=s[i];
		for (int j=p;j<=i;j++) minn=min(minn,s[i]);
		res+=minn;
	}
	cout<<res;
	return 0;
} 
