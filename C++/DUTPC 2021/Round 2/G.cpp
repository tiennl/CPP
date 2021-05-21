#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005

map <ll,ll> a,x,y,mark;

int main(){
	FIO
	ll n,aa,bb;
	cin>>n>>aa>>bb;
	for (int i=0;i<n;i++){
		cin>>a[i];
		mark[a[i]]=1;
	}
	for (int i=0;i<n;i++){
		bool ok=0;
		if (mark[aa-a[i]]==1 && aa-a[i]!=a[i]){
			x[a[i]]=1;
			x[aa-a[i]]=1;
			ok=1;
		}
		if (!ok){
			if (mark[bb-a[i]]==1 && bb-a[i]!=a[i]){
				y[a[i]]=1;
				y[bb-a[i]]=1;
				ok=1;
			}
		}
		if (!ok){
			cout<<-1;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for (int i=0;i<n;i++)
		if (x[a[i]]==1) cout<<0<<" ";
		else cout<<1<<" ";
	return 0;
}
