#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
ll a[N],b[N];
int main(){
	FIO
	ll n,d=0,d1=0,d2=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	sort(a,a+n); 
	sort(b,b+n);
	while (d2<n){
		if (b[d2]>a[d1]){
			d++;
			d1++;
			d2++;
		}
		else d2++;
	}
	cout<<d;
	return 0;
}
