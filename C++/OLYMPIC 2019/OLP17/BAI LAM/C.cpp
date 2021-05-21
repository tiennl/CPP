#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<long long>());
	for (int i=1;i<=n;i++)
		if (a[i]>=i) res=i;
	cout<<res;
	return 0;
}
