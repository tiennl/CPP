#include <bits/stdc++.h>
long long x[100000];
using namespace std;
void print(long long n, long long x[]){
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<endl;
}
void binary(long long i, long long n, long long x[]){
	for (int j=0;j<=1;j++){
		x[i]=j;
		if (i<n) binary(i+1,n,x);
		else print(n,x);
	}
}
int main(){
	long long n;
	cin>>n;
	binary(1,n,x);
	return 0;
}
