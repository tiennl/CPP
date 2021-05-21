#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,m,pos=0;
	bool ok=false;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n-1;i++){
		pos=lower_bound(a,a+n,a[i]+m)-a;
		if (a[pos]==a[i]+m){
			cout<<a[i]<<" "<<a[pos]<<endl;
			ok=true;
		}
		pos=0;
	}
	if (!ok) cout<<-1;
	return 0;
}
