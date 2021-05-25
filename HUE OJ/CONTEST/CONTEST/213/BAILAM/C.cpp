#include <bits/stdc++.h>
int a[200001];
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,maxn=0;
	while (cin>>n){
		a[n]=1;
		maxn=max(maxn,n);
		if (n==0) break;
	}
	maxn++;
	for (int i=1;i<=maxn;i++)
		if (a[i]==0){
			cout<<i;
			return 0;
		}
	return 0;
}

