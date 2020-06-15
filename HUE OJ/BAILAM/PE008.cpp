#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10000005

ll a[N];

int main(){
	FIO
	ll n,num,n3,res=0;
	cin>>n;
	for (int i=3;i<=sqrt(n);i+=2)
		for (int j=1;j<=i;j+=2)
			if (__gcd(i,j)==1){
				num=i*(i+j);
				for (int k=1;k<=n;k++){
					n3=num*(ll)k;
					if (n3<=n) a[n3]++;
					else break;		
				}
			}	
	for (int i=1;i<=n;i++) 
		if (a[i]==1) res++;
	cout<<res;
	return 0;
}
