#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
long long uoc(long long x){
	long long s=0;
	if (isPrime(x)) return 1;
	for (int i=1;i<=sqrt(x);i++)
		if (x%i==0)
			if (i==1) s+=1;
			else if (x/i==i) s+=i;
			else s+=(i+x/i);
	return s;
}
int main(){
	long long t,a,b,res=0;
	cin>>t;
	while (t--){
		cin>>a>>b;
		res=0;
		for (int i=a;i<=b;i++) 
			if (!isPrime(i)) cout<<i<<" "<<uoc(i)<<endl;
		cout<<res<<endl;
	}
	return 0;
}
