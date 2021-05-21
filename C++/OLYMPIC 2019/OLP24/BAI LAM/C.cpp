#include <bits/stdc++.h> 
using namespace std;
int main(){ 
    long long n,res=0; 
   	cin>>n;
   	if (n<2){
   		cout<<0;
   		return 0;
	}
   	res=n;
   	for (long long p=2;p*p<=n;p++) 
        if (n%p==0){  
            while (n%p==0) n/=p; 
            res-=res/p; 
        }  
    if (n>1) res-=res/n;
    cout<<res; 
    return 0; 
} 
// Euler's Totient Function (Phi ham Euler) 
// https://www.geeksforgeeks.org/eulers-totient-function/
