#include <bits/stdc++.h>
long long a[100000];
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<long long>());
	res=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>i) res+=a[i]-i;
	cout<<res;
	return 0;
}
