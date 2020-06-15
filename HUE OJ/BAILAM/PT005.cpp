#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,y=0,m=0,d=0;
	cin>>n;	
	y=n/365;
	n%=365;
	m=n/30;
	n%=30;
	d=n;
	if (y>0) cout<<y<<" years"<<endl;
	if (m>0) cout<<m<<" months"<<endl;
	if (d>0) cout<<d<<" days";
	return 0;
}
