#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,sum=0;
	double m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n,greater<ll>());
	double t=sum/(4*m);
	if (a[(ll)m-1]<t) cout<<"No";
	else cout<<"Yes";
	return 0;
}
