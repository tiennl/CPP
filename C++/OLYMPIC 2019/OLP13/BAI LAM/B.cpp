#include <bits/stdc++.h>
long long a[1000000],b[1000000];
using namespace std;
int main(){
	long long n,m,k=0,res=0;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++){
		res=0;
		k=0;
		for (int j=i;j<n;j++){
			if (res+a[j]<m){
				res+=a[j];
				k++;
				b[k]=a[j];
			//	cout<<res<<endl;
			}
			else if (res+a[j]>m){
				while (res<m && res+a[j]>m && j<n && k>0){
					res-=b[k];
					k--;
				//	for (int h=1;h<=k;h++) cout<<b[h]<<" ";cout<<endl;
				}
				if (res+a[j]<=m){
					res+=a[j];
					k++;
					b[k]=a[j];
					//for (int h=1;h<=k;h++) cout<<b[h]<<" ";
					//cout<<endl;
				}
				if (res==m){
					for (int h=1;h<=k;h++) cout<<b[h]<<" ";
					cout<<endl;
				}
			}
			else if (res+a[j]==m){
				res+=a[j];
				k++;
				b[k]=a[j];
				for (int h=1;h<=k;h++) cout<<b[h]<<" ";
				cout<<endl;
			}	
		}
	}
	return 0;
}
