#include <iostream>
#include <math.h>
using namespace std;
int a[100000];
int b[100000];
bool snt(int x){	
	if (x<2){
		return false;
	}
	else if (x>2){
		if (x%2==0){
			return false;
		}
		for (int ii=2;ii<=sqrt(x);ii++){
			if (x%ii==0){
				return false;
			}
		}
	}
	return true;
}
main(){
	int n,p,dem,j,k,m;
	cin>>n>>p;
	m=0;
	for (int i=2;i<=n;i++)
	 	if (snt(i)==true){
	 		m++;
	 		a[m]=i;
		} 
	for (int i=1;i<=n;i++){
		if (snt(i)==true) b[i]++;
		else 
		if (i>2){
			j=i;
			k=1; 
			while (j>1){
				if (j%a[k]==0){
					b[a[k]]++;
					j/=a[k];
					if (j==0) break;
				}
				else k++;
			}
		} 
	}
	if (snt(p)==true) cout<<b[p];
	else{
		// chay mang tim tich = p
	}
}
