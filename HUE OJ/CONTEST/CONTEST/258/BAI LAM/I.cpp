#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	double s,r1,pi=2*acos(0);
	cin>>s>>r1;
	cout<<fixed<<setprecision(2)<<sqrt(r1*r1-s/pi);
	return 0;
}
