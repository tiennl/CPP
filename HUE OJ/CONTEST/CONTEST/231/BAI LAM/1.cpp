#include <bits/stdc++.h> 
using namespace std; 
int arr[1000];
int findFourElements(int arr[], int n) { 
    unordered_map<int, pair<int, int> > mp; 
    for (int i=0;i<n-1;i++) 
        for (int j=i+1;j<n;j++) 
            mp[arr[i]+arr[j]] ={i,j}; 
    int d=INT_MIN; 
    for (int i=0;i<n-1;i++){ 
        for (int j=i+1;j<n;j++) { 
            int abs_diff=abs(arr[i]-arr[j]); 
            if (mp.find(abs_diff)!=mp.end()){ 
                pair<int, int> p=mp[abs_diff]; 
                if (p.first!=i && p.first!=j && p.second!=i && p.second!=j) 
                    d=max(d,max(arr[i],arr[j])); 
            } 
        } 
    } 
    return d; 
} 
int main(){ 
    int s,n,res=0;
    while (cin>>n){
        if (n==0) return 0;
        res=0;
        for (int i=0;i<n;i++) cin>>arr[i]; 
        res=findFourElements(arr,n); 
        if (res==INT_MIN) cout<<"no solution"; 
        else cout<<res;
        cout<<endl;
    }
    return 0; 
} 
