#include <bits/stdc++.h>
using namespace std;
long long a[1000000],f[1000000];
int main(){
	long long n,result=1;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[1]=1;
	for (int i=2; i<=n; i++) {
    	if (a[i]>a[i-1])
    	    f[i] = f[i-1]+1;
    	else f[i]=1;
   		 result = max(result, f[i]);
	}	
	cout<<result;
	return 0;
}



