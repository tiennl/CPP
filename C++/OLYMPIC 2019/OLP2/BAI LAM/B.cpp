#include <bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
	int n;
	long long res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n-1;i++)
		if (a[i]<=0 && a[i+1]>=0){
			if (a[0]<=0 && a[n-1]>=0) res=2*(0-a[0])+2*a[n-1];
			else if (a[0]<=0 && a[n-1]<=0) res=2*(0-a[0]);
			break;
		}
	if (a[0]>=0) res=2*a[n-1];
	if (a[n-1]<=0) res=2*abs(a[0]);
	cout<<res;
	return 0;
}
