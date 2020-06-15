#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(ll n){
	ll s=0;
	while (n>0){
		s+=(n%10)*(n%10);
		n/=10;
	}
	return s;
} 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0;
	bool check[1001];
	for (int i=0;i<1001;i++) check[i]=true;
	cin>>n;
	while (true){
		n=sum(n);
		res++;
		if (n==1){
			cout<<res;
			return 0;
		}
		else if (!check[n]){
			cout<<-1;
			return 0;
		}
		else check[n]=false;
	}
	return 0;
}
