#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long a[10000000];
int main(){
	long long n,res=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=1;i<n;i++) 
		if (a[i]!=a[i-1]) res++;
	if (n==0) cout<<0;
	else cout<<res;
	return 0;
}
