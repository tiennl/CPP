#include <iostream>
using namespace std;
int a[50];
int b[1000];
main(){
	int n,i,kt,kt1,kq,dem;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	kt=1;
	kq=n-1;
	while (kt==1){
		kq++;
		dem=0;
		kt1=0;
		for (int j=1;j<=kq;j++) b[j]=0;
		for (i=1;i<=n;i++){
			if (a[i]<=kq && b[a[i]]==0){b[a[i]]=1;dem++;}
			else{
			    if (a[i]%kq==0 && b[kq]==0){dem++;b[kq]=1;} 
			    else
				    if (a[i]%kq!=0 && b[a[i]%kq]==0){dem++;b[a[i]%kq]=1;}
			}
		}
		if (dem==n){
			kt=0;
			cout<<kq;
			break;
		}	
	}
}
