#include <bits/stdc++.h> 
#include<tr1/unordered_map>
using namespace std; 
long long arr[1000];
long long findFourElements(long long arr[], long long n){ 
    std::tr1::unordered_map<long long, pair<long long, long long> > mp; 
    for (int i=0;i<n-1;i++) 
        for (int j=i+1;j<n;j++) 
            mp[arr[i]+arr[j]] ={i,j}; 
    long long d=INT_MIN; 
    for (int i=0;i<n-1;i++){ 
        for (int j=i+1;j<n;j++) { 
            int abs_diff=abs(arr[i]-arr[j]); 
            if (mp.find(abs_diff)!=mp.end()){ 
                pair<long long, long long> p=mp[abs_diff]; 
                if (p.first!=i && p.first!=j && p.second!=i && p.second!=j) 
                    d=max(d,max(arr[i],arr[j])); 
            } 
        } 
    } 
    return d; 
} 
int main(){ 
    long long s,n,res=0;
    while (cin>>n){
        if (n==0) return 0;
        res=0;
        for (int i=0;i<n;i++) cin>>arr[i]; 
        res=findFourElements(arr,n); 
        if (res==INT_MIN) cout<<"no solution"<<endl; 
        else cout<<res<<endl;
    }
    return 0; 
} 
