#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll f[10000000],g[10000000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (cin>>n){
		if (n==-1) return 0;
		if (n%2!=0) cout<<0<<endl;
		else{
			for (int i=0;i<=n;i++) f[i]=0,g[i]=0;
		    f[0]=1;f[1]=0;
			g[0]=0;g[1]=1; 
		    for (int i=2;i<=n;i++){ 
		        f[i]=f[i-2]+2*g[i-1]; 
		        g[i]=f[i-1]+g[i-2]; 
	    	} 
		  	cout<<f[n]<<endl;
		}
	}
	return 0;
}
/*
 https://www.algorithmist.com/index.php/UVa_10918
 https://www.geeksforgeeks.org/tiling-with-dominoes/
*/
