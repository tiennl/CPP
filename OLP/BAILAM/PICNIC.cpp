#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
ll a[10]={0}; 
int main(){
	FIO
	ll n,num,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		a[num]++;
	}
	res=a[3]+a[4];
	if (a[3]>=a[1]) res+=a[2]/2+a[2]%2;
	else{
		a[1]-=a[3];
		a[2]=a[2]*2+a[1];
		res+=a[2]/4;
		if (a[2]%4!=0) res++;
	}
	cout<<res;
	return 0;
}
