#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,num,s=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		s+=num;
	}	
	cout<<fixed<<setprecision(4)<<s/(float)n;
	return 0;
}