#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	cout<<pow(a+b+c,2)-(pow(a,2)+pow(c,2)+pow(e,2));	
	return 0;
}

