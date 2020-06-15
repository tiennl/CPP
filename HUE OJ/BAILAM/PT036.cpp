#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
#define M 1000

bool prime[N],res[N];
ll pp[N],check[M][M];

int main(){
	FIO
	ll t,n,kk,m=1000,k=-1,coun=0,num;
	cin>>t;
	for (int i=2;i<=m;i++) prime[i]=true;
	for (int p=2;p*p<=m;p++)  
        if (prime[p])
            for (int i=p*2;i<=m;i+=p) prime[i]=false;
    for (int i=2;i<m;i++)
    	if (prime[i] && i<=m){
    		k++;
    		pp[k]=i;
		}
	k++;
	for (int i=0;i<k;i++)
		for (int j=0;j<k;j++) 
			check[i][j]=0;
	for (int i=0;i<k-1;i++) check[pp[i]][pp[i+1]]=1,check[pp[i+1]][pp[i]]=1;
	for (int i=2;i<=m;i++) res[i]=false;
	for (int i=2;i<=m;i++){
		bool ok=0;
		num=i-1;
		if (prime[i])
		for (int j=0;j<k;j++) 
			if (num-pp[j]>0 && check[pp[j]][num-pp[j]]==1){
				ok=1;
				break;
			}
		if (ok==1) res[i]=true;
	}
	while (t--){
		cin>>n>>kk;
		coun=0;
		for (int i=2;i<=n;i++)
			if (res[i]) coun++;
		if (coun>=kk) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}
