#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ll a,b,res=0;
	ll d[]={0,3,6,9,11,14,17};
	cin>>a>>b;
	for (int i=a;i<=b;i++){
		int ok=0;
		for (int j=0;j<7;j++)
			if (i%19==d[j]){
				ok=1;
				break;
			}
		if (ok==1) res++;
	}	
	cout<<res;
	return 0;
}
