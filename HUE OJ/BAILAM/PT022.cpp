#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isLeapYear(ll n){
	if ((n%4==0 && n%100!=0) || (n%400==0)) return true;
	return false;
}

int main(){
	FIO
	ll t,n;
	cin>>t;
	while (t--){
		cin>>n;
		if (isLeapYear(n)) cout<<"leap year"<<endl;
		else cout<<"none"<<endl;
	}	
	return 0;
}
