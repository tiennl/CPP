#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define ull unsigned long long
inline ull mulMod (ull a, ull b, ull mod){
    ull x=0,y=a%mod;
    while (b){
        if (b&1) x=(x+y)%mod;
        y=(y<<1)%mod;
        b>>=1;
    }
    return x%mod;
}
inline ull powMod(ull base, ull pow, ull mod){
    ull x=1,y=base;
    while (pow){
        if (pow&1) x=mulMod(x,y,mod);
        y=mulMod(y,y,mod);
        pow>>=1;
    }
    return x%mod;
}
inline bool isPrime(ull n, int it){
    if (n<2 || (n!=2 && n%2==0)) return 0;
    ull s=n-1;
    while (s%2==0) s/=2;
    srand(time(0));
    for (int i=0;i<it;i++) {
        ull temp=s,r=powMod(rand()%(n-1)+1,temp,n);
        while (temp!=n-1 && r!=1 && r!=n-1){
            r=mulMod(r,r,n);
            temp*=2;
        }
        if (r!=n-1 && temp%2==0) return 0;
    }
    return 1;
}
int main() {
    ull t,n;
    cin>>t;
    while (t--){
		cin>>n;
    	while (!isPrime(n,5)) n++;
    	cout<<n<<endl;
    }
    return 0;
}
