#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	double a,b;
	ll aa,bb,res=0;
	cin>>a>>b;
	aa=a;
	bb=b;
	if (aa<a) aa++;
	for (int i=aa;i<=bb;i++) res+=i;
	cout<<res;
	return 0;
}
