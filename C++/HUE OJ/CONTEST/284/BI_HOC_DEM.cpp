#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10005

string a[N];

ll toNum(string s){
	ll r=0;
	for (int i=0;i<s.size();i++)
		r=r*10+(s[i]-'0');
	return r;
}

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
		if (a[i]!="mumble" && toNum(a[i])!=i){
			cout<<"something is fishy";
			return 0;
		}
	cout<<"makes sense";
	return 0;
}
