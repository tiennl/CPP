#include <bits/stdc++.h>
using namespace std;
string nhiphan(long long n){
	string s="";
	if (n==0) return "0";
	while (n>0){
		s=(char)(n%2+48)+s;
		n/=2;
	}
	return s;
}
int main(){
	long long n;
	cin>>n;
	cout<<nhiphan(n);
	return 0;
}
