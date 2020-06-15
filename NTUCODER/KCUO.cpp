#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll n,coun=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=(n-coun)/2;j++) cout<<"*";
		for (int j=1;j<=coun;j++) cout<<"D";
		for (int j=1;j<=(n-coun)/2;j++) cout<<"*";
		if (i<=n/2) coun+=2;
		else coun-=2;
		cout<<endl;
	}
	return 0;
}
