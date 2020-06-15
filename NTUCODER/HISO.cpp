#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,maxx=0,minn=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	minn=a[0];
	maxx=0;
	for (int i=0;i<n;i++){
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]-minn);
	}
	cout<<maxx;
	return 0;
}
