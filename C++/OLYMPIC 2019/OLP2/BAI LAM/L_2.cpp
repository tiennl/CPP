#include <bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],add[1000000];
int main(){
	int t;
	long long n,max_d=0,max_dd=0,maxx=-10000,ahi=0;
	cin>>t;
	while (t--){
		cin>>n;
		if (n>0) cin>>a[0];
		max_d=0;
		max_dd=0;
		maxx=a[0];
		if (a[0]>0) max_d+=a[0];
		add[0]=a[0];
		b[0]=a[0];
		for (int i=1;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		if (b[n-1]<=0){
			cout<<b[n-1]<<" "<<b[n-1]<<endl;
		}
		else{
		for (int i=1;i<n;i++){
			add[i]=add[i-1]+a[i];
			if (a[i]>0) max_d+=a[i];
			maxx=max(maxx,a[i]);
		}
		if (max_d>0) cout<<max_d<<" ";
		else cout<<maxx<<" ";
		int  sum=0,res=-10000000000;
    	for (int i=0;i<n;i++){
        	sum+=a[i];
        	res=max(res,sum);
        	sum=max(sum,0);
    	}
 		cout<<res<<endl;
		}
	}
	return 0;
}

