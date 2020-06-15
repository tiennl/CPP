#include <bits/stdc++.h>
using namespace std;
long long uoc(long long x){
	long long ans=0;
	for (int i=1;i<x;i++)
		if (x%i==0) ans+=i;
	return ans;
}
int main(){
	long long a,b;
	cin>>a>>b;
	if (uoc(a)==b && uoc(b)==a) cout<<"YES";
	else cout<<"NO";
	return 0;
}
