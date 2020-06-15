#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll v,h;
	while (cin>>v>>h){
		if (v==-1 && h==-1) return 0;
		cout<<fixed<<setprecision(6)<<v/9.8*sqrt(2*9.8*h+v*v)<<endl; 
	}	
	return 0;
}
