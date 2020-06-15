#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

ll C(ll m){
	ll r=0,x=m,y=m-1;
	if (x%2==0) x/=2;
	else y/=2;
	r=x*y;
	return r;
}

int main(){
	FIO
	ll n,even=0,odd=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]%2==0) even++;
		else odd++;
	}
	if (even==n) cout<<C(n);
    else{
	    if (odd==n)
    	  	if (n%2!=0) cout<<0;
    	    else cout<<C(n);  	
		else
		    if (odd%2!=0) cout<<even*odd;
		    else cout<<C(even)+C(odd);
        }
	return 0;
}
