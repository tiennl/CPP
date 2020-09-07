#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 405

ll dp[N][N][N]; 

ll solve(ll i, ll s, ll coun, vector<ll>& a, ll k){ 
    if (i<0)  return 0; 
    if (i==0){ 
        if (coun==0) return 0; 
        ll temp=s%coun; 
        if (temp!=0) return 0; 
        ll avg=s/coun; 
        if (avg==k) return 1; 
    } 
    if (dp[i][s][coun]!=-1) return dp[i][s][coun]; 
    ll no=solve(i-1,s,coun,a,k); 
    ll ok=solve(i-1,s+a[i],coun+1,a,k); 
    ll tt=ok+no; 
    dp[i][s][coun]=tt; 
    return tt; 
} 
  
ll countWay(ll n, ll k, ll* a){ 
    vector<ll> r; 
    r.push_back(-1); 
    for (int i=0;i<n;i++) r.push_back(a[i]); 
    memset(dp,-1,sizeof dp);
    ll res=solve(n,0,0,r,k); 
    return res; 
} 

int main(){
	FIO
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for (int i=0;i<n;i++) cin>>a[i];
    cout<<countWay(n,k,a); 
	return 0;
} 
