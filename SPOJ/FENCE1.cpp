#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	double l,PI=2*acos(0.0);
	while (cin>>l){
		if (l==0) return 0;
		cout<<fixed<<setprecision(2)<<l*l/(2*PI)<<endl;
	}
	return 0;
}
