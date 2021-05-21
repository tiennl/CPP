#include <bits/stdc++.h>
using namespace std;
long long find(long long n, long long m, long long p){
	long long res=0;
	for (int i=1;i<=m;i++)
		res+=min(n,p/i);
	return res;
}

int main(){
	long long n,m,k,l=0,r=0,g=0,tt=0,res=-1;
	cin>>n>>m>>k;
	l=1;
	r=n*m;
	while (l<=r){
		g=(l+r)/2;
		if (find(n,m,g)>=k){
			cout<<g<<" "<<find(n,m,g)<<endl;
			res=g;
			r=g-1;
		} 
		else l=g+1;
	}
	cout<<res;
	return 0;
}
