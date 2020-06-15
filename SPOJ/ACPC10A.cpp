#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a1,a2,a3;
	while (cin>>a1>>a2>>a3){
		if (a1==0 && a2==0 && a3==0) 
			return 0;
		else{
			if (a2-a1==a3-a2) cout<<"AP "<<a3+(a3-a2)<<endl;
			else cout<<"GP "<<a3*(a3/a2)<<endl;
		}
	}
	return 0;
}
