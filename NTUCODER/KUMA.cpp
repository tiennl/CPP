#include <bits/stdc++.h>
using namespace std;
int main(){
	long long m,n,t,a=0,res=0;
	cin>>m>>n>>t;
	a=n/(m+1);
	res=(n-a)*t;
	cout<<res;
	return 0;
}
    
