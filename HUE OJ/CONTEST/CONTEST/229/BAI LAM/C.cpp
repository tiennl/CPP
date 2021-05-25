#include <bits/stdc++.h>
long long s[100000];
using namespace std;
int main(){
	long long n,k=0;
	cin>>n;
	s[0]=3;
	while (s[k]<n){
		k++;				
		s[k]=s[k-1]*2+k+3;
	}
	while (k>0){
		if (n==s[k-1]+1){
			cout<<"m";
			return 0;
		}
		if (n>s[k-1]+1 && n<=s[k-1]+3){
			cout<<"o";
			return 0;
		}
		if (n>s[k-1]+k+3) n=n-s[k-1]-k-3;
		k--;
	}
	if (n==1) cout<<"m";
	else cout<<"o";
	return 0;
}
