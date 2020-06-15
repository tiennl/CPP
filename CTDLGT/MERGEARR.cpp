#include <iostream>
using namespace std;
long long a[500000],b[500000],c[1000000];
int main(){
	long long m,n;
	cin>>m>>n;
	for (int i=0;i<m;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	long long i=0,j=0,k=-1;
	while (i<m && j<n){
		k++;
		if (a[i]>b[j]) c[k]=b[j],j++;
		else c[k]=a[i],i++;
	}
	if (i==m){
		for (int h=j;h<n;h++){
			k++;
			c[k]=a[h];
		} 
	}
	else if (j==n){
		for (int h=i;h<m;h++){
			k++;
			c[k]=a[h];
		}
	}
	cout<<m+n<<endl;
	for (int i=0;i<=k;i++) cout<<c[i]<<" ";
	return 0;
}
