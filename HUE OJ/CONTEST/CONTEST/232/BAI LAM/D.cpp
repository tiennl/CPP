#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	int n;
	cin>>n;
	long long s = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		s += a[i];
	}
	cout<<fixed<<setprecision(4)<<s/(float)n;	
}
