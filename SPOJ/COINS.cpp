#include <bits/stdc++.h>
using namespace std;
#define ull long long 
ull tocoins(ull n){
	ull a=n/2,b=n/3,c=n/4;
	if (a+b+c>n) return tocoins(a)+tocoins(b)+tocoins(c);
	return n;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ull n;
	while (cin>>n){
		cout<<tocoins(n)<<endl;
	}
	return 0;
}
