#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000000
ll a[N],b[N]; 
int main(){
	ll n,d,d1,d2;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	sort(a,a+n); 
	sort(b,b+n);
	d=0;
	d1=0;
	d2=0;
	while (d2<n){
		if (b[d2]>a[d1]) d++,d1++,d2++;
		else d2++;
	}
	cout<<d;
	return 0;
}
