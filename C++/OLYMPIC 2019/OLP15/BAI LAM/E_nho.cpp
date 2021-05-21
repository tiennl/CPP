#include <bits/stdc++.h>
long long a[10000000],f[10000000];
using namespace std;
int main(){
	long long n,res=1;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
    	f[i]=0;
    	for (int j=0;j<i;j++) 
			if (a[j]<a[i]){
        		f[i]=max(f[i],f[j]+1);
    		}
    	res=max(res,f[i]);
	}
	cout<<n-res;
	return 0;
}
