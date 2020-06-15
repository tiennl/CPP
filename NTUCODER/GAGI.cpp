#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,res=0;
	cin>>a>>b;
	while (a<b){
		res++;
		a*=2;
	}
	if (a==b) cout<<res;
	else cout<<res-1;
	return 0;
}
