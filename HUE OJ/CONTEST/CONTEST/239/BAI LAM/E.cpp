#include <bits/stdc++.h> 
using namespace std;
#define ll long long
ll a[10000000];
int main(){ 
    ll n,odd=0,res=0;
    cin>>n;
    for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]%2!=0){
			cout<<0;
			return 0;
		}
	}
    while (odd==0){
    	res++;
    	for (int i=0;i<n;i++){
    		a[i]/=2;
    		if (a[i]%2!=0){
    			odd=1;
    			cout<<res;
    			return 0;
			}
		}
	}
	return 0; 
} 
