#include <bits/stdc++.h>
using namespace std;
long long a[1000000],maxsum[1000000];
main(){
	long long n,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	maxsum[0]=maxsum[1]=0;
	for (int i=2;i<n;i++){
		maxsum[i]=max(a[i]+a[i-1]+a[i-2]+maxsum[i-3],a[i]+a[i-1]+a[i-2]);
		res=max(res,maxsum[i]);
	}
	cout<<res;
	return 0;
}
