#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

int main(){
	FIO
	ll m,n,t,pen=0,res=0,coun=0;
	cin>>m>>n>>t;
	while (pen<n){
        pen++;
        coun++;
		res+=t;
		if (coun==m){
			pen++;
			coun=0;
		}
	}
	cout<<res;
	return 0;
}
