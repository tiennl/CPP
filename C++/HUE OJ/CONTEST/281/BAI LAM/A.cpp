#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],b[N];

int main(){
	FIO
	ll n,res=0,add=0,adda=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i]>>b[i];
	for (int i=n-1;i>=0;i--){
		if (a[i]%b[i]!=0){
			a[i]+=adda;
			add=b[i]-(a[i]%b[i]);
			adda+=add;
			res+=add;	
		}
	}
	cout<<res;
	return 0;
}
