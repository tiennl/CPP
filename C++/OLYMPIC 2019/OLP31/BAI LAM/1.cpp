#include <bits/stdc++.h>
long long x[1000000],d[1000000];
long long n,r=0;
using namespace std;
void nghiem(long long x[]){
	r++;
	//for (int i=1;i<=n;i++) cout<<x[i]<<" ";
	//cout<<endl;
}
void hoanvi(long long i){
	for (int j=1;j<=2;j++){
		x[i]=j;
		if (i==n) nghiem(x);
			else hoanvi(i+1);
	}
}
int main(){
	cin>>n;
	hoanvi(1);
	cout<<r;
	
	return 0;
}
