#include <bits/stdc++.h> 
using namespace std; 
#define ull long long
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
ull a[1000000],b[1000000]; 
int main() 
{ 
	FIO
    ll n=-1,m,num;
    cin>>m;
    for (ll i=0;i<m;i++){
    	cin>>num;
    	if (num>0){
    		n++;
    		a[n]=num;
		}
	}
	n++; 
    for (ll i = 0; i < n; i++) 
        b[i] = a[i] * a[i]; 
    sort(a, a + n); 
    sort(b, b + n); 
    ll x=0,y=0,z=0; 
    for (ll i=0; i<n; i++) 
    { 
        ll p = i+1; 
        ll q = i+1; 
        for (ll j=i+1; j<n; j++) 
        { 
            while (p<n-1 && b[i]+b[j]>=b[p+1]) 
                p++; 
  
            q = max(q, p); 
            while (q<n-1 && a[i]+a[j]>a[q+1]) 
                q++; 
            if (b[i]+b[j]==b[p]) 
            { 
                x += max(p - j - 1, 0LL); 
                y++;  
                z += q - p; 
            } 
            else
            { 
                x += max(p - j, 0LL); 
                z += q - p; 
            } 
        } 
    } 
    cout << x << " " << y << " " << z; 
    return 0; 
} 
