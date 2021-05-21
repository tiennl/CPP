#include <bits/stdc++.h>
using namespace std;
unsigned long long a[1000000],b[1000000];
int main(){
	unsigned long long n,res=0,so=0,maxx=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		maxx=a[i];
		for (int j=i+1;j<=n;j++){
			maxx=max(maxx,a[j]);
			if (a[j]<maxx){
				b[i]++;
			//	cout<<maxx<<endl;
			}
			else break;
		}
		res+=b[i];
	}
//	for (int i=1;i<n;i++) cout<<b[i]<<" ";
//	cout<<endl;
	cout<<res;
	return 0;
}
/*
6
7 3 4 1 3 2
*/
