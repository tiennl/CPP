#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	float n0,n,d;
	cin>>t;
	while (t--){
		cin>>n0>>n>>d;
		cout<<fixed<<setprecision(4)<<n0*(pow(d,n)-1)/(d-1)<<endl;
	}
	return 0;
}
