// day con co tong chia het cho k
// 1e9 = 10^9
#include <bits/stdc++.h>
using namespace std;
int f[1001][1001];
int n,k,i,j,a[1000],s;
int o(int x){
	return (x>=0) ? x : (x+k);
}
int main() {
    s=0;
    cin >> n >> k;
    for(i=1; i<=n; i++){
    	cin >> a[i];
    	a[i]%=k;
    	s = (s+a[i])%k;
	}
	// co so quy hoach dong
	f[0][0]=0;
	for(int i=1; i<k; i++){
		f[0][i]=1e9;
	}
 
	for(i=1; i<=n; i++){
		for(j=0; j<k; j++){
			f[i][j] = min(f[i-1][j], f[i-1][o(j-a[i])]+1);
			// f[i][j] = min(f[i-1][j], f[i-1][o(j-a[i])]+1); 
 
			// cung chinh la 
			//for (int i=0; i<m; i++)
			//g[i] = max(f[i], f[(i-x+m) % m] + 1);
		}
	}
	cout << n-f[n][s%k];
	return 0;
}
