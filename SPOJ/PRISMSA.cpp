#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define db double 
#define N 1000005

int main(){
	FIO
	ll t ;
	cin>>t;
	while (t--){
		db v,s=0,a;
		cin>>v;
		a=pow(4*v,0.3333333333333333);
		s=3*a*a*sqrt(3)/2;
		cout<<fixed<<setprecision(10)<<s<<endl;
	}	
	return 0;
}
