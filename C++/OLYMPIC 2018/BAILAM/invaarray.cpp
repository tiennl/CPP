#include <iostream>
using namespace std;
long long a[1000000];
main(){
	int n;
	unsigned long long max,v1,v2,s1,s2;
	cin>>n;
	max=0;
	v1=0;v2=0;s1=0;s2=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			if (a[i]*i+a[j]*j>max){
				max=a[i]*i+a[j]*j;
				v1=i;
				v2=j;
				s1=a[i];
				s2=a[j];
			}
			if (a[i]*i+a[j]*j==max){
				if (j-i<v2-v1){
					v1=i;v2=j;s1=a[i];s2=a[j]; 
					max=a[i]*i+a[j]*j;
			 	}
			 	if (j-i==v2-v1 && i<v1 && j<v2){
			 		v1=i;v2=j;s1=a[i];s2=a[j];
			 		max=a[i]*i+a[j]*j;
				}
			}
		}
			
	cout<<v1<<" "<<v2<<" "<<s1<<" "<<s2<<" "<<max;
}
