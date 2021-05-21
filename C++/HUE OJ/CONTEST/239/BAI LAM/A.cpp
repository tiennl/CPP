#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int main(){ 
    ll n; 
    while (cin>>n){
		if (n==0) return 0;
		ll res=0;
	   	if (n<2) cout<<0<<endl;
	   	else{
		   	res=n;
		   	for (ll p=2;p*p<=n;p++) 
		        if (n%p==0){  
		            while (n%p==0) n/=p; 
		            res-=res/p; 
		        }  
		    if (n>1) res-=res/n;
		    cout<<res<<endl;
		}
	}
    return 0; 
} 
