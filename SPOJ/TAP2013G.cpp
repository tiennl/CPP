#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005

ll q[N],n[N];

int main(){
	FIO
	ll s,res=0;
	cin>>s;
	for (int i=0;i<s;i++) cin>>q[i];
	for (int i=0;i<s;i++) cin>>n[i];
	sort(q,q+s);
	sort(n,n+s);
	ll i=0,j=0;
	while (i<s && j<s){
		if (q[i]<n[j]) res++,i++,j++;
		else j++;
	}
	cout<<res;
	return 0;
}
