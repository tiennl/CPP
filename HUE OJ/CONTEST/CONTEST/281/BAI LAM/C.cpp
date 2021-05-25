#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull unsigned long long 

ull getSetBitsFromOneToN(ull N){ 
    ull two=2,ans=0; 
    ull n=N; 
    while(n){ 
        ans+=(N/two)*(two>>1); 
        if((N&(two-1))>(two>>1)-1) ans+=(N&(two-1))-(two>>1)+1; 
        two<<=1; 
        n>>=1; 
    } 
    return ans; 
} 

int main(){
	FIO
	ull n,m,t=2,res=0;
	cin>>n;  
    cout<<getSetBitsFromOneToN(n);
	return 0;
}
