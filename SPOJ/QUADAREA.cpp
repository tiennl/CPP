#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t;
	cin>>t;
	while (t--){
		double a,b,c,d,p,s;
		cin>>a>>b>>c>>d;
		p=(a+b+c+d)/2;
		s=sqrt((p-a)*(p-b)*(p-c)*(p-d));
		cout<<fixed<<setprecision(2)<<s<<endl;
	}
	return 0;
}
