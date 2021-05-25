#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,r=0;
string s;
void solve(string s, ll n, ll open){
	if (n%2!=0 && !open) return;
	if (n==0){
		if (open==0){
			r++;
			if (r==m) cout<<s;
		}
		return;
	}
	if (open>n) return;
	solve(s+"(",n-1,open+1);
	if (open>0) solve(s+")",n-1,open-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	solve(s,n,0);
	return 0;
}
