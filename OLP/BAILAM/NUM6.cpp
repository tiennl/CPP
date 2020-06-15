#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000000
ll a[N],aa[N],b[N]={0};
int main(){
	FIO
	ll n,res=0,m=-1,m1,m2;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (n<6){
		cout<<0;
		return 0;
	}
	sort(a,a+n);
	m1=a[0]*a[1]*a[n-1];
	m2=a[n-1]*a[n-2]*a[n-3];
	if (m1>m2){
		res=m1;
		b[0]=-1;
		b[1]=-1;
		b[n-1]=-1;
	}
	else{
		res=m2;
		b[n-1]=-1;
		b[n-2]=-1;
		b[n-3]=-1;
	}
	for (int i=0;i<n;i++)
		if (b[i]==0){
			m++;
			aa[m]=a[i];
		}
	m++;
	m1=aa[0]*aa[1]*aa[m-1];
	m2=aa[m-1]*aa[m-2]*aa[m-3];
	res+=max(m1,m2);
	cout<<res;
	return 0;
}
