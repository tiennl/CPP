#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long 
ull powMod(ull a, ull b, ull p)
{
    ull ret=1;
    a%=p;
    b%=p-1;
    while (b>0){
        if (b%2>0)  
            ret=ret*a%p;
        a=a*a%p; 
        b/=2;
    }
    return ret;
}
int main(){
	FIO
	ull n,l,mod=1e9+7,res=0;
	cin>>n>>l;
	res=((powMod(4,n+1,mod)-1)*333333336)%mod;
	res*=l;
	cout<<res%mod;
	return 0;
}

/*
123456 987654
865977765

l^2*(4^(N+1)-1)/3

*/



