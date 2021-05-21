#include <bits/stdc++.h>
using namespace std;
long long a[3];
int main(){
	unsigned long long res=0;
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
//	res=max(max(a[0]+a[1]*a[2],a[0]*a[1]*a[2]),a[0]+a[1]+a[2]);
	if (a[0]>1 && a[1]>1 && a[2]>1) cout<<a[0]*a[1]*a[2];
	else{
	if (a[0]+a[1]*a[2]>res) res=a[0]+a[1]*a[2];
//	if (a[0]*a[1]*a[2]>res) res=a[0]*a[1]*a[2];
	if (a[0]+a[1]+a[2]>res) res=a[0]+a[1]+a[2];
	cout<<res;
}
	return 0;
}

