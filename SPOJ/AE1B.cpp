#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
main(){
	int n,k,s,kt=0,d=0;
	long long sum=0;
	cin>>n>>k>>s;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=n-1;i>=0;i--){
		sum+=a[i];
		d++;
		if (sum>=k*s){
			kt=1;
		}
		if (kt==1) break;
	}
	if (kt==1) cout<<d;
	else cout<<"0";
}
