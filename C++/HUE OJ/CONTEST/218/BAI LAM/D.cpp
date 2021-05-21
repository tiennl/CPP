#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,n,res=0;
	cin>>a>>b>>n;	
	while (n>0){
		n-=a;
		res++;
		if (n<=0){
			cout<<res;
			return 0;
		}
		else n+=b;
	}
	cout<<res;
	return 0;
}
