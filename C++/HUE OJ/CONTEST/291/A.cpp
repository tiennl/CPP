#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll k,same=0,diff=0,res=0;
	string s1,s2;
	cin>>k>>s1>>s2;
	for (int i=0;i<s1.size();i++)
		if (s1[i]==s2[i]) same++;
		else diff++;
	if (k>=same) res=2*same+diff-k;
	else res=k+diff;
	cout<<res;
	return 0;
}
