#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
string s[N],l[N],r[N];
ll same(string a, string b){
	string l1="",r1="",l2="",r2="";
	if (a.size()>b.size()) swap(a,b);
	for (int i=a.size();i>=0;i--){
		l1=a.substr(0,i);
		r1=a.substr(a.size()-i,i);
		l2=b.substr(0,i);
		r2=b.substr(b.size()-i,i);
		if (l1==l2 && r1==r2) return i;
	}
	return 0;
}
int main(){
	FIO
	ll n,k,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if(same(s[i],s[j])==k) res++;
	cout<<res;
	return 0;
}
