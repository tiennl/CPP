#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); 
#define ll long long 
int main(){
	FIO
	ll n,p=1,k=2,res=0,coun=0;
	cin>>n;
	if (n==1){
		cout<<1;
		return 0;
	}
	for (int i=1;i<n;i++){
		res=(p/k+1)*k;
		p=res;
		coun++;
		if (coun==k){
			coun=0;
			k++;
		}
	//	cout<<res<<" ";
	}	
	cout<<res;
	return 0;
}
