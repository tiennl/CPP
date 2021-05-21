#include<bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,k,pos,coun=0,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n-1;i++){
		pos=lower_bound(a,a+n,a[i]+k)-a;
		coun=0;
		if (a[pos]==a[i]+k && pos!=i) coun=pos-i;
		else if (a[pos-1]<a[i]+k && pos!=i) coun=pos-i-1;
		//cout<<i<<" "<<coun<<" "<<pos<<endl;
		if (coun>0) res+=coun;
	}
	cout<<res;
	return 0;
}
    
