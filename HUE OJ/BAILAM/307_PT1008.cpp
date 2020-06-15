#include<bits/stdc++.h>
using namespace std;
main(){
	long long n;
	float x,so,res=1;
	cin>>x>>n;
	int k=0;
	float so_hang_k=1;
	for (int i=1;i<n;i++){
		k++;
		so=2*k;
		so_hang_k=(so_hang_k*x*x)/so/(so-1);
		if (k%2!=0) res-=so_hang_k;
		else res+=so_hang_k;
	}
	cout<<fixed<<setprecision(6)<<res;
	return 0;
}
//1-2+2/3-4/45
