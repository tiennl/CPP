#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		double r1,r2,r3,r4;
		cin>>r1>>r2>>r3;
		r4=(r1*r2*r3)/(r1*r2+r1*r3+r2*r3+2*sqrt(r1*r2*r3*(r1+r2+r3)));
		cout<<fixed<<setprecision(6)<<r4<<endl;
	}
	return 0;
}

// http://mathworld.wolfram.com/SoddyCircles.html
