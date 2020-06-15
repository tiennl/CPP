#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll m,n,k,res=0;
	cin>>m>>n>>k;
	if (m%n==0 && m>=n){
		cout<<0;
		return 0;
	}
	res=0;
	while (m%n!=0){
		m+=k;
		res++;
		if (res==1000001){
			cout<<-1;
			return 0;
		}
	}
	cout<<res;
	return 0;
}
