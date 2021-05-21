#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		res+=(a[i]/2);
		a[i]%=2;
		if (a[i]==1 && a[i+1]>0){
			res+=1;
			a[i+1]--;
		}
	}
	cout<<res;
	return 0;
}

