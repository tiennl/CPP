#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool isPrime(ll n){
	if (n<2) return false;
	for (int i=2;i<=sqrt(n);i++)
		if (n%i==0) return false;
	return true;
}

int main(){
	FIO
	string s;
	ll num=0;
	getline(cin,s);
	s+='a';
	for (int i=0;i<s.size();i++)
		if (isdigit(s[i])) num=num*10+(s[i]-'0');
		else if (isdigit(s[i-1]) && !isdigit(s[i])){
			if (isPrime(num)) cout<<num<<endl;
			num=0;
		}	
	return 0;
}
