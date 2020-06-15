#include <iostream>
#include <math.h>
using namespace std;
long long a[300000],maxx[300000];
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	maxx[1]=2;
	for (int i=2;i<n;i++) {
		if (a[i]==a[i-1]+a[i-2]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=2;
		res=max(res,maxx[i]);
	}
	if (res>2) cout<<res;
	else cout<<-1;
	return 0;
}
