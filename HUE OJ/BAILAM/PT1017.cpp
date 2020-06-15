#include <bits/stdc++.h>
using namespace std;
long long scs(unsigned long long n){
	long long res=0;
	while (n>0){
		res++;
		n/=10;
	}
	return res;
}
int main(){
	unsigned long long n,m,base1=0,base2,k;
	cin>>n;
	m=n;
	n*=n;
	base2=pow(10,scs(n)/2);
	if (scs(n)%2==0) base1=base2;
	else{
		base1=base2*10;
		base2=base1;
	}
	if ((n/base1+n%base2==m && m!=0) || m==1) cout<<"YES";
	else cout<<"NO";
	return 0;
}
