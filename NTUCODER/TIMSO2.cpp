#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	if (n>=0 && n<=9){
		if (n==0) cout<<10;
		else cout<<n;
		return 0;
	} 
    stack<int> digits; 
    for (int i=9;i>=2 && n>1;i--){ 
        while (n%i==0){ 
            digits.push(i); 
            n/=i; 
        } 
    } 
    if (n!=1){
		cout<<-1;
        return 0;
	}
    ll k=0; 
    while (!digits.empty()){ 
        k=k*10+digits.top(); 
        digits.pop(); 
    }  
    cout<<k;
	return 0;
}
