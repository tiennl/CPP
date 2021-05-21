#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long a[1000000],maxx[1000000];
int main(){
	long long n,res=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	maxx[0]=1;
	for (int i=1;i<n;i++) {
		if (a[i]>a[i-1]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=1;
		res=max(res,maxx[i]);
	}
	if (n==0) cout<<0;
	else cout<<res;
	return 0;
}
