#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define mod 1000000007

void mulMatrix(ll T[3][3], ll M[3][3]){ 
    ll a, b, c, d, e, f, g, h, i; 
    a = T[0][0] * M[0][0] +  
        T[0][1] * M[1][0] +  
        T[0][2] * M[2][0]; 
    b = T[0][0] * M[0][1] +  
        T[0][1] * M[1][1] +  
        T[0][2] * M[2][1]; 
    c = T[0][0] * M[0][2] +  
        T[0][1] * M[1][2] +  
        T[0][2] * M[2][2]; 
    d = T[1][0] * M[0][0] +  
        T[1][1] * M[1][0] +  
        T[1][2] * M[2][0]; 
    e = T[1][0] * M[0][1] +  
        T[1][1] * M[1][1] +  
        T[1][2] * M[2][1]; 
    f = T[1][0] * M[0][2] +  
        T[1][1] * M[1][2] +  
        T[1][2] * M[2][2]; 
    g = T[2][0] * M[0][0] +  
        T[2][1] * M[1][0] +  
        T[2][2] * M[2][0]; 
    h = T[2][0] * M[0][1] +  
        T[2][1] * M[1][1] +  
        T[2][2] * M[2][1]; 
    i = T[2][0] * M[0][2] +  
        T[2][1] * M[1][2] +  
        T[2][2] * M[2][2]; 
    T[0][0] = a % mod; 
    T[0][1] = b % mod; 
    T[0][2] = c % mod; 
    T[1][0] = d % mod; 
    T[1][1] = e % mod; 
    T[1][2] = f % mod; 
    T[2][0] = g % mod; 
    T[2][1] = h % mod; 
    T[2][2] = i % mod; 
} 

void power(ll T[3][3], ll n){
	if (n==0 || n==1) return;
	ll M[3][3]={{ 1, 1, 1 },  
                { 1, 0, 0 },  
                { 0, 1, 0 }};
	power(T,n/2);
	mulMatrix(T,T);
	if (n%2) mulMatrix(T,M); 
}

ll triFibo(ll n){
	ll T[3][3]={{ 1, 1, 1 },  
                { 1, 0, 0 }, 
                { 0, 1, 0 }};
	if (n==0 || n==1) return 0;
	else power(T,n-2);
	return T[0][0];  
}

int main(){
	FIO
	ll n;
	cin>>n;
	if (n==0) cout<<0;
	else cout<<triFibo(n+2);
	return 0;
}

