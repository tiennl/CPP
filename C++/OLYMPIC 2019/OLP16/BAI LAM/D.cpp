#include <bits/stdc++.h>
long long a[10000000],b[10000000];
using namespace std;
int main(){
	long long n,q,l,r,res=0,m=0,m1=0,m2=0;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	while (q--){
		cin>>l>>r;
		res=0;
		m1=a[l];
		m2=a[l];
		for (int i=1;i<=m;i++) b[i]=0;
		for (int i=l;i<=r;i++){
			b[a[i]]++;
			m1=min(m1,a[i]);
			m2=max(m2,a[i]);
		}
		for (int i=m1;i<=m2;i++)
			if (b[i]>0) res+=(i*b[i]*b[i]);
		cout<<res<<endl;
	}
	return 0;
}
