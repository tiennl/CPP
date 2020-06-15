#include <bits/stdc++.h>
using namespace std;
long long reverse(long long x){
	long long res=0;
	while (x>0){
		res=res*10+(x%10);
		x/=10;
	}
	return res;
}
int main(){
	long long t,a,b;
	cin>>t;
	while (t--){
		cin>>a>>b;
		cout<<reverse(reverse(a)+reverse(b))<<endl;
	}
	return 0;
}
