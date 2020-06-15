#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long
int first(ull n){
	while (n>=10) n/=10;
	return n;
}
ull count(ull n){
	if (n<10) return n;
	ull f,l,res;
	res=n/10+9;
	f=first(n);
	l=n%10;
	if (l<f) res--; 
	return res;
}
int main(){
	FIO
	ull a,b,res=0;
	cin>>a>>b;
	cout<<count(b)-count(a-1);
	return 0;
}
