#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if ((abs(a[i])<abs(a[j])) || (abs(a[i])==abs(a[j]) && a[i]<a[j])) swap(a[i],a[j]);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
