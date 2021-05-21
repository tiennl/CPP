#include <bits/stdc++.h>
long long a[100];
using namespace std;
int main(){
	long long t,n,res=0,sl=10,m=0,r=0;
	cin>>t;
	while (t--){
		cin>>n;
		sl=10;
		for (int i=0;i<=9;i++) a[i]=0;
		if (n==0) cout<<"Awake!"<<endl;
		else{
			int j=0;
			while (sl>0){
				j++;
				m=n*j;
				while (m>0){
					r=m%10;
					if (a[r]==0){
						sl--;
						a[r]=1;
						if (sl==0){
							res=j;
							break;
						}
					}
					m/=10;
				}
			}
			cout<<n*j<<endl;
		}
	}
	return 0;
}
