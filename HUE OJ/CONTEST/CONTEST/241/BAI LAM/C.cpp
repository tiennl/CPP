#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100000],b[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll k=0,n,so;
	cin>>n;
	for (int i=2;i<=n;i+=2){			
		k++;
		if (i%2==0) a[k]=i;
		else b[k]=i;
		if ((i+1)%2==0) a[k]=i+1;
		else b[k]=i+1;
	}
	cout<<(n-1)/2<<endl;
	for (int i=1;i<=n/2;i++){
		cout<<1<<" ";
		for (int i=1;i<=k;i++) cout<<a[i]<<" "<<b[i]<<" ";
		so=a[k];
		for (int j=k;j>=2;j--) a[j]=a[j-1];
		a[1]=b[1];
		for (int j=1;j<=k;j++) b[j]=b[j+1];			
		b[k]=so;
		cout<<endl;
	}
	return 0;
}
