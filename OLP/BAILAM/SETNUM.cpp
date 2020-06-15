#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000000];
int main(){
	long long n,res=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=1;i<n;i++) 
		if (a[i]!=a[i-1]) res++;
	cout<<res;
	return 0;
}
