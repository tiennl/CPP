#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N],b[N];

int main(){
	FIO
	ll n,s=0,m=-1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++){
		s=0;
		for (int j=i;j<n;j++){
			s+=a[j];
			m++;
			b[m]=s;
		}
	}
	m++;
	sort(b,b+m);
	for (int i=0;i<m;i++) cout<<b[i]<<" ";
	return 0;
}
