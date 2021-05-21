#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005
struct num{
	ll value,coun;
};
num a[N];
bool SS(num &a, num &b){
	if (a.value!=b.value) return a.value>b.value;
	return a.coun<b.coun;
}
int main(){
	FIO
	ll n,k,s=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i].value>>a[i].coun;
	cin>>k;
	sort(a,a+n,SS);
	for (int i=n-1;i>=0;i--){
		s+=a[i].coun;
		if (s>=k){
			cout<<a[i].value;
			return 0;
		}
	}
	return 0;
}
