#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int sochuso(long long n){
	int d=0;
	while (n>0){
		d++;
		n/=10;
	}
	return d;
}
int main(){
	long long n,res=100,maxx;
	cin>>n;
	for (int i=1;i<=sqrt(n);i++){
		if (n%i==0){
			maxx=max(sochuso(i),sochuso(n/i));
			res=min(res,maxx);
		}
	}
	cout<<res;
	return 0;
}
