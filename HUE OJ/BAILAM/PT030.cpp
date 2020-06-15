#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool prime[N];
ll pp[N];

int main(){
	FIO
	ll n,p,exp,k=-1,res=1,mod=1e9+7;
	cin>>n;
	for (int i=0;i<=n;i++) prime[i]=true;
	for (int p=2;p*p<=n;p++)  
        if (prime[p])
            for (int i=p*2;i<=n;i+=p) 
                prime[i]=false; 
    for (int p=2;p<=n;p++) 
        if (prime[p]){
        		k++;
        		pp[k]=p;
        	}
    k++;
    for (int i=0;i<k;i++){ 
        p=pp[i]; 
        exp=0; 
        while (p<=n){ 
            exp+=(n/p); 
            p*=pp[i]; 
        } 
        res*=(exp+1); 
        if (res>mod) res%=mod;
    } 
    cout<<res; 
	return 0;
}
