#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,num,res=0;
	cin>>n;
	while (n--){
		cin>>num;
		if (num%3==0 || num%7==0) res++;
	}	
	cout<<res;
	return 0;
}
