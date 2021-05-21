#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 200005

ll a[N],b[N];

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for (int i=0;i<n;i++){
		if (a[i]<b[n/2]) cout<<b[n/2]<<endl;
		else cout<<b[n/2-1]<<endl;
	}	
	return 0;
}
