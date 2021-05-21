#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
} 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll num=0;
	getline(cin,s);
	s+=" ";
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9') num=num*10+(s[i]-'0');
		else{
			if (isPrime(num)) cout<<num<<endl;
			num=0;
		}
	return 0;
}
