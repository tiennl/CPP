#include <bits/stdc++.h>
using namespace std;
char a[100][100],b[100];
int main(){
	long long n,m,k,d,same=0;
	bool ok;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) cin>>a[i][j];
	k=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++){
			cin>>b[k];
			k++;
		}
	d=-1;
	for (int i=0;i<n-m+1;i++) 
		for (int j=0;j<n-m+1;j++){
			same=0;
			d=-1;
			ok=1;
 			for (int h=i;h<i+m;h++){
				for (int l=j;l<j+m;l++){
					d++;
					if (a[h][l]==b[d]) same++;
					else ok=0;
				}
				if (!ok) break;
			}
			if (same==m*m){
				cout<<"Yes";
				return 0;
			}
		
		}
	cout<<"No";
	return 0;
}

