#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 20000009

ll a[N],b[N];
map <ll,int> coun;

int main(){
	FIO
	ll n,m;	
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		coun[a[i]]++;
	}
	for (int i=0;i<m;i++){
		cin>>b[i];
		coun[b[i]]++;
	}
	for (int i=0;i<n;i++)
		if (coun[a[i]]%2!=0){
			cout<<a[i];
			return 0;
		}
	for (int i=0;i<m;i++)
		if (coun[b[i]]%2!=0){
			cout<<b[i];
			return 0;
		}
	return 0;
}
