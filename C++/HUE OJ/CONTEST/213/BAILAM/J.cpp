#include <bits/stdc++.h>
long long a[30000000],b[30000000],sl[30000000];
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,t,res=0,k=0,so=0,p,key=0,ii,ll,rr;
	cin>>n>>t;
	for (int i=0;i<n;i++) cin>>a[i];
	b[0]=a[0];
	sl[0]=1;
	for (int i=1;i<n;i++)
		if (a[i]!=a[i-1]){
			k++;
			b[k]=a[i];
			sl[k]=1;
		}
		else sl[k]++;
	k++;
	for (int i=0;i<k-2;i++){
		key=b[i]+t;
		ll=i+2;
		rr=k-1;
    	ii=(ll+rr)/2;
    	while (ll!=ii && ii!=rr){
        	if (b[ii]>=key) rr=ii;
        	else ll=ii;
   		    ii=(ll+rr)/2;
    	}
		if (ii>i && b[ii]-b[i]<=t) res+=(ii-i-1+sl[i]+sl[ii]-2);
	}
	cout<<res;
	return 0;
}
