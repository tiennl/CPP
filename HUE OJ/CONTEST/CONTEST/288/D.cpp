#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[500]={0};

int main(){
	FIO
	ll res=0;
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++){
		a[s[i]]++;
		res=max(res,a[s[i]]);
	}
	cout<<res;
	return 0;
}
