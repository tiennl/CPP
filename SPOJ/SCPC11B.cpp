#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		bool ok=1;
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		if (a[0]>200 || 2*(1422-a[n-1])>200) ok=0;
		else{
			for (int i=0;i<n-1;i++)
				if (a[i+1]-a[i]>200){
					ok=0;
					break;
				}
		}
		if (ok) cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;	
	}
	return 0;
}
