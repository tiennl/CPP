#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],coun[N];

int main(){
	FIO
	ll n;
	cin>>n;	
	for (int i=0;i<n;i++){
		cin>>a[i];
		coun[a[i]]++;
	}
	sort(a,a+n);
	cout<<a[n-1]<<" "<<coun[a[n-1]];
	return 0;
}
