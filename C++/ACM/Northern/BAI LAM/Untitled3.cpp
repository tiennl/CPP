#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
ll a[25000];
void findTriangle(ll a[], ll n) 
{ 
    ll b[n + 2]; 
    for (int i = 0; i < n; i++) 
        b[i] = a[i] * a[i]; 
    sort(a, a + n); 
    sort(b, b + n); 
    int x=0,y=0,z=0; 
    for (int i=0; i<n; i++) 
    { 
        int p = i+1; 
        int q = i+1; 
  
        for (int j=i+1; j<n; j++) 
        { 
            while (p<n-1 && b[i]+b[j]>=b[p+1]) 
                p++; 
  
            q = max(q, p); 
            while (q<n-1 && a[i]+a[j]>a[q+1]) 
                q++; 
            if (b[i]+b[j]==b[p]) 
            { 
                x += max(p - j - 1, 0); 
                y++;  
                z += q - p; 
            } 
            else
            { 
                x += max(p - j, 0); 
                z += q - p; 
            } 
        } 
    } 
  
    cout << x<<" "<<y<<" "<<z; 
}  
int main() 
{ 

    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    findTriangle(a, n); 
    return 0; 
} 
