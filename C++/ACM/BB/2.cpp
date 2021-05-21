#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define db double 
#define N 100005

ll a[N];
map <ll,ll> coun; 

int main(){
	FIO
	ull n,s;
	cin>>n>>s;
	for (int i=0;i<n;i++){
		cin>>a[i];
		coun[a[i]]++;
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		if (coun[a[i]]>1){
			ll p=lower_bound(a+i,a+n,s/a[i])-a;
			if (coun[[]])
		}
	}
	return 0;
}
