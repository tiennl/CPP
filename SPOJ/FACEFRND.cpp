#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000][1000],f[10000000],b[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0,k=-1;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2];
		for (int j=3;j<3+a[i][2];j++){
			k++;
			cin>>b[k];
		}
		f[a[i][1]]=1;
	}
	k++;
	for (int i=0;i<k;i++)
		if (f[b[i]]==0){
			res++;
			f[b[i]]=1;
		}
	cout<<res;
	return 0;
}
