#include <bits/stdc++.h>
using namespace std;
long long tohop(long long n, long long k)
{
    long long c=1;
   for (int i=1;i<=k;i++,n--)
      c=c*n/i;
   return c;
}
int main(){
	long long t,n,k;
	cin>>t;
	while (t--){
		cin>>n>>k;
		cout<<tohop(n,k)<<endl;
	}
	return 0;
}
