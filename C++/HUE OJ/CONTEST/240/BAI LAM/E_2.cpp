#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
int main() { 	 	
    int n; cin >> n; 	
    int a[n]; 	
    for(int i=0; i<n; i++) cin>>a[i]; 	
    map<ll,int> f; 	
    f[0] = 1; 	
    ll s = 0; 	
    ll d = 0; 	
    for(int i = 0; i< n; i++) { 	
        s += a[i]; 	
        d += f[s]++; 
    } 	
    cout << d; 
    return 0; 
}
