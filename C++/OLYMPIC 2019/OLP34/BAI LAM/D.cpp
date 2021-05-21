#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); 
#define ll long long
#define N 100000 
#define maxN 1000000001
ll a[N],f[N];
int main(){
	FIO
	ll n,k,res=0,s=0,mi,p_mi;
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=k;i++) s+=a[i];
	if (k<=n) cout<<s<<endl; 
	for (int i=k+1;i<=n;i++){
		s+=a[i];
		mi=*min_element(a+1,a+i+1);
		p_mi=find(a+1,a+i+1,mi)-a;
		s-=mi;
		a[p_mi]=maxN;
		cout<<s<<endl;
	}	
	return 0;
}
