#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	float a,b,c;
	cin>>a>>b>>c;
	cout<<fixed<<setprecision(4)<<a*b*sin(c)/2;	
	return 0;
}
