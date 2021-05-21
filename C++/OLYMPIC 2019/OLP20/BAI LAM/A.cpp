#include <bits/stdc++.h>
int a[10000000],sl[10000000],num[10000000];
using namespace std;
int main(){
	long long n,d,k=0,res=0;
	cin>>n>>d;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<300000;i++) sl[i]=0,num[i]=0;
	if (n==d){
		cout<<0;
		return 0;
	}
	a[0]=1;
	a[n-1]=1;
	sl[0]=1;
	num[0]=a[0];
	for (int i=1;i<n;i++)
		if (a[i]==a[i-1]) sl[k]++;
		else{
			k++;
			sl[k]=1;
			num[k]=a[i];
		}
	k++;
	for (int i=0;i<k;i++) 
		if (num[i]==0) res+=sl[i]/d;
	cout<<res;
	return 0;
}
