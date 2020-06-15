#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long 
int main(){
	FIO
	ull	g,y;
	cin>>g>>y;
	for (ll d=1;d<g/2;d++){
		ll r=g/2+2-d;
		if ((d-2)*(r-2)==y){
			cout<<min(d,r)<<" "<<max(d,r);
			return 0;
		}
	}
	return 0;
}
