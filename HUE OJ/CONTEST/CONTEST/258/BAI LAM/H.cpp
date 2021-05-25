#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int digits(int x){
	int r=0;
	while (x>0){
		r+=x%10;
		x/=10;
	}
	return r;
}
int main(){
	FIO
	int m,n,minn,res=0;
	cin>>m>>n;
	minn=digits(m);
	for (int i=m+1;i<=n;i++)
		minn=min(minn,digits(i));
	for (int i=m;i<=n;i++)
		if (digits(i)==minn) res++;
	cout<<res;
	return 0;
}
