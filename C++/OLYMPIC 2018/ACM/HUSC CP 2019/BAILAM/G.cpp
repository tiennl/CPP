#include <bits/stdc++.h>
using namespace std;
unsigned long long a[100000],s[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,m,res=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]%m==0) res++;
		s[i]=s[i-1]+a[i];
		if (i>0 && s[i]%m==0) res++;
	}
	for (int i=0;i<n-2;i++)
		for (int j=i+2;j<n;j++)
			if ((s[j]-s[i])%m==0) res++;
	cout<<res;
	return 0;
}
