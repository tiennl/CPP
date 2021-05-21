#include <bits/stdc++.h>
int a[10],n[10000000];
using namespace std;
int next(int n){
	int maxn=0,minn=0,i=-1;
	while (n>0){
		i++;
		a[i]=n%10;
		n/=10;
	}
	sort(a,a+4);
	for (int i=3;i>=0;i--) maxn=maxn*10+a[i];
	for (int i=0;i<4;i++) minn=minn*10+a[i];
	return maxn-minn;
}
int main(){
	int k=1;
	cin>>n[1];
	while (n[k]!=6174){
		k++;
		n[k]=next(n[k-1]);
	}
	cout<<k<<endl<<n[k-1];
	return 0;
}
