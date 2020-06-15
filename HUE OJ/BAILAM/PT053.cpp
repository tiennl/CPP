#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	ll n,coun=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		coun=0;
		for (int j=0;j<n;j++)
		 	if (a[i]<a[j]) coun++;
		cout<<coun+1<<endl;
	}
	return 0;
}
