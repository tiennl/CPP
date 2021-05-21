#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n,res=0;
	cin>>n;
	n*=2;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i+=2) res+=a[i];
	cout<<res;
	return 0;
}
