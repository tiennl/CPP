#include <iostream>
#include <algorithm>
long long a[2000000],b[2000000],c[2000000];
using namespace std;
main(){
	unsigned long long n,k,kt=0,res,d,dem,m,i;
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	a[n]=-1;
	d=1;
	m=-1;
	i=1;
	while (i<=n){
		if (a[i]==a[i-1]) d++;
		else{
			m++;
			b[m]=a[i-1];
			c[m]=d;	
			d=1;
		}	
		i++;
	}

	kt=0;
	dem=0;
	res=1;
	for (int i=m;i>=0;i--){
		if (c[i]>=4){
			kt=1;
			cout<<b[i]*b[i];
			break;
		}
		else if (c[i]>=2){
			dem++;
			res*=b[i];
			if (dem==2){
				kt=1;
				cout<<res;
				break;
			}
		}
	}
	if (kt==0) cout<<"0";
}

