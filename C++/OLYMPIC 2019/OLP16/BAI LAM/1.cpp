#include <bits/stdc++.h>
unsigned long long a[10000000];
using namespace std;
int main(){
    unsigned long long n,k,res=0,sum=0,l=0,r=0;	 
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    while (l<n){
        while (r<n && sum+a[r]<=k){
           	sum+=a[r];
           	if (sum==k) res++;
           	r++;
       }
       sum-=a[l];
       l++;
    }
    cout<<res;
    return 0;
}
