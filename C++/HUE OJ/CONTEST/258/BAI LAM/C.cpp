#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000000
ll a[N]={0}; 
int main(){
	FIO
	ll n,num;
	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>num;
		a[num]=1;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==0){
			cout<<i;
			return 0;
		}
	return 0;
}
