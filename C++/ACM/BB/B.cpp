#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 2005

ll arr[N];

ll findMin(ll arr[], ll n){ 
    ll sum=0;  
    for (int i=0;i<n;i++) sum+=arr[i]; 
    bool dp[n+1][sum+1];
    for (int i=0;i<=n;i++) dp[i][0]=true; 
    for (int i=1;i<=sum;i++) dp[0][i]=false; 
    for (int i=1;i<=n;i++){ 
        for (int j=1;j<=sum;j++){  
            dp[i][j]=dp[i-1][j];  
            if (arr[i-1]<=j) 
                dp[i][j]|=dp[i-1][j-arr[i-1]]; 
        } 
    }   
    ll diff=INT_MAX; 
    for (int j=sum/2;j>=0;j--){ 
        if (dp[n][j]==true){ 
            diff=sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 

int main(){
	FIO
	ll n,m=-1,s=0,d=0;
	cin>>n;
	for (int i=0;i<n;i++){
		ll num;
		cin>>num;
		if (num%2==0){
			m++;
			arr[m]=num/2;
			m++;
			arr[m]=num/2;
		}
		else{
			m++;
			arr[m]=num;
		}
		s+=num;
	}
	m++;
	d=findMin(arr,m);
	ll x=(s+d)/2;
	ll y=s-x;
	cout<<max(x,y);
	return 0;
}

