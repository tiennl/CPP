#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	float r,PI=3.14159,p,s;
	cin>>r;
	p=PI*r*(float)2;
	s=PI*r*r;
	cout<<"Chu vi = "<<fixed<<setprecision(4)<<p<<endl;
	cout<<"Dien tich = "<<fixed<<setprecision(4)<<s;	
	return 0;
}
