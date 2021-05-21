#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll n,num,coun=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		if (num%2!=0) coun++;
	}
	if (coun%2==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
