#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n;
	unsigned long long res=1,base=1000000007;
	cin>>n;
	bool kt=0;
	long long a[]={n,n+1,n+2,n+3};
	for (int i=0;i<4;i++){
		res*=a[i];
		if (res%4==0 && kt==0) res/=4,kt=1;
		if (res>base) res%=base;
	}
	cout<<res;
	return 0;
}
