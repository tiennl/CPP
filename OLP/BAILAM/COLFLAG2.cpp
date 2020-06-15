#include <bits/stdc++.h>
using namespace std;
int a[256],b[256];
int main(){
	int n,m,k,so,co=0,res=0,d;
	cin>>n>>m;
	for (int i=0;i<=255;i++) a[i]=0;
	for (int i=0;i<n+m;i++){
		cin>>so;
		a[so]++;
	}
	k=-1;
	for (int i=0;i<=255;i++)
		if (a[i]>0){
			k++;
			b[k]=a[i];
		}
	k++;
	sort(b,b+k);
	d=k;
	while (co<n){
		d--;
		if (b[d]+co<n){
			co+=b[d];
			res++;
		}
		else break;
	}
	cout<<res+1;
	return 0;
}



