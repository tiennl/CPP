#include <bits/stdc++.h>
long long a[10000000],maxx[10000000];
using namespace std;
int main(){
	long long n,q,k,res=0;
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>a[i];
	while (q--){
		cin>>k;
		res=0;
		for (int i=0;i<n;i++) maxx[i]=0;
		if (a[0]<=k) maxx[0]=1;
		for (int i=1;i<n;i++) {
			if (a[i]<=k) maxx[i]=maxx[i-1]+1;
			else maxx[i]=0;
			res=max(res,maxx[i]);
		}
		cout<<res<<endl;	
	}	
	return 0;
}
