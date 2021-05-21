#include <bits/stdc++.h>
using namespace std;
long long a[100000],b[100000];
int main(){
	long long n,k,res=0,d=0,kt=0,dem=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]%k==0) dem++;
	}
	if (dem==n){
		cout<<1;
		return 0;
	}
	for (int i=1;i<=n;i++){
		d=1;
		b[1]=a[i];
		kt=0;
		for (int j=i+1;j<=n;j++){
			kt=0;
			for (int h=1;h<=d;h++)
				if ((a[h]+a[j])%k==0){
					kt=1;
					break;
				}
			if (kt==0){
				d++;
				b[d]=a[j];
			}
		    if (d>res) res=d;
		}	
	}
	if (k==1 || res==1) cout<<1; 
	else cout<<res;
	return 0;
}


