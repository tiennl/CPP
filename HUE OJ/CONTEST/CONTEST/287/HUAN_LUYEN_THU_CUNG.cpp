#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long 
#define N 1000005

int main(){
	FIO
	ll x,y,a,b,res=0;
	cin>>x>>y>>a>>b;
	while (x<y/a && x<=(x+b)/a){
		x*=a;
		res++;
	}
	if ((y-x)%b==0) res+=(y-x)/b-1;
	else res+=(y-x)/b;
	cout<<res;
	return 0;
}
