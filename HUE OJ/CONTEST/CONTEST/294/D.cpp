#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1005

ll a[N];

int main(){
	FIO
	ll n,m=1,d=0,s1=0,res=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++){
			m=2;
			d=a[j]-a[i];
			s1=a[j];
			for (int k=j+1;k<n;k++)
				if (a[k]-s1==d){
					s1=a[k];
					m++;
				}
			res=max(res,m);
		}
	cout<<res;
	return 0;
}
