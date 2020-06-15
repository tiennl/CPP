#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main(){
	float a,b,c,d,res=0;
	cin>>a>>b>>c>>d;
	res=sqrt((c-a)*(c-a)+(d-b)*(d-b));
	cout<<fixed<<setprecision(4)<<res;
	return 0;
}
