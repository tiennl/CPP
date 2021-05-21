ll modPrimePow(ll a, ll b, ll p){
    ll r=1;
    a%=p;
    b%=p-1;
    while (b>0){
        if (b%2>0) 
            r=r*a%p;
        a=a*a%p; 
        b/=2;
    }
    return r;
}
