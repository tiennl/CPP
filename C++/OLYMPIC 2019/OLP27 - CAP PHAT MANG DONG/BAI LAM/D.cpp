#include <bits/stdc++.h>
long long a[100000],b[100000];
using namespace std;
int main(){
	long long n,res=0,minij=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			minij=0;
			int sl=j-i+1;
			minij=*min_element(b+i,b+j-i+1);
		//	cout<<i<<" "<<j<<" "<<minij<<endl;
			res=max(res,min(minij,a[i]+a[j]));
		}
	}
	cout<<res;
	return 0;
}
/*
4
7 2 5 3
4 6 3 8
*/
