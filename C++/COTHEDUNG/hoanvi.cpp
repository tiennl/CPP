#include <bits/stdc++.h>
long long x[1000000],d[1000000];
long long m,n;
using namespace std;
void nghiem(){
	for (int j=1;j<=n;j++) cout<<x[j]<<" ";
	cout<<endl;
}
void hoanvi(long long i){
	for (int j=1;j<=n;j++)
		if (d[j]==0){
			x[i]=j;
			d[j]=1;
			if (i==n) nghiem();
			else hoanvi(i+1);
			d[j]=0;
		}
}
int main(){
	cin>>n;
	hoanvi(1);
	return 0;
}
