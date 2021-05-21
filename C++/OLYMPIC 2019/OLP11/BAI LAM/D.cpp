#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
int main(){
	long long n,k=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
/*	sort(a,a+n);
	while (a[0]!=0){
		k++;
		if ((a[n-1]>1 && a[0]==1 && a[n-2]==1 && n>2) || (a[n-1]>1 && a[0]==1 && n==2)){
			for (int i=0;i<n-1;i++) a[i]--;
			if (k%2!=0){
				cout<<"First";
				return 0;
			}
			else if (k%2==0){
				cout<<"Second";
				return 0;
			}
		}
		else{
			a[n-1]=0;
			n--;
		}
	}
	if (k%2==0) cout<<"First";
	else cout<<"Second";*/
	cout<<"First";
	return 0;
}
