#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,l=0,r=0;
	cin>>n;
	if ((n/7)%2==0){
		l=7;
		r=0;
		n%=7;
		l-=n;
		r+=n;
	}
	else{
		l=0;
		r=7;
		n%=7;
		l+=n;
		r-=n;
	}
	cout<<l<<" "<<r;
	return 0;
}
