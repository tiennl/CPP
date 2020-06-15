#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=1;i<n;i++)
		if (a[i]<a[i-1]){
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}
