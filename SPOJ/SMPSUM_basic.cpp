#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,sum=0;
	cin>>a>>b;
	for (int i=a;i<=b;i++) sum+=i*i;
	cout<<sum;
	return 0;
}
