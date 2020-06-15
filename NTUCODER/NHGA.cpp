#include <bits/stdc++.h>
long long a[100000];
using namespace std;
int main(){
	long long n,minn=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	minn=a[1]-a[0];
	for (int i=2;i<n;i++) 
		minn=min(minn,a[i]-a[i-1]);
	cout<<minn;	
	return 0;
}
