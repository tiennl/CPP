#include <bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main(){
	int t,k=0,n,so;
	cin>>t;
	while (t--){
		cin>>n;
		int k=0;
		for (int i=2;i<=n;i+=2){
			k++;
			if (i%2==0) a[k]=i;
			else b[k]=i;
			if ((i+1)%2==0) a[k]=i+1;
			else b[k]=i+1;
		}
		for (int i=1;i<=n/2;i++){
		//	for (int j=1;j<=k;j++) cout<<a[j]<<" "<<b[j]<<endl;
			cout<<1<<" ";
			for (int i=1;i<=k;i++) cout<<a[i]<<" "<<b[i]<<" ";
			cout<<1<<endl;
			so=a[k];
			for (int j=k;j>=2;j--) a[j]=a[j-1];
			a[1]=b[1];
			for (int j=1;j<=k;j++) b[j]=b[j+1];
			b[k]=so;
		}
		cout<<endl;
	}	
	return 0;
}
