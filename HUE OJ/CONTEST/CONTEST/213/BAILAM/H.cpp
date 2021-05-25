#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,res=0,k=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			k=sqrt(i*i+j*j);
			if (k*k==i*i+j*j && k>j && i+j+k<=n){
				res++;
			//	cout<<i<<" "<<j<<" "<<k<<endl;
			}
		}
	cout<<res;
	return 0;
}
