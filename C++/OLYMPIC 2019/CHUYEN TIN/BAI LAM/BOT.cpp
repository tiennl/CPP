#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000000 
ll a[N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,sum=0,l=0,r=0,s=0,res=INT_MIN;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		sum+=a[i];
		if (res<sum){
			res=sum;
			l=s;
			r=i;
		}
		if (sum<0){
			sum=0;
			s=i+1;
		}
	}
	cout<<l+1<<" "<<r+1<<" "<<res;
	return 0;
}
