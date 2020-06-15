#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll a,b;
	cin>>a>>b;
	if (a<=0 && b>=0) cout<<"Zero";
	else if (a>0 || (b<0 && abs(b-a)%2!=0)) cout<<"Positive";
	else cout<<"Negative";
	return 0;
}
