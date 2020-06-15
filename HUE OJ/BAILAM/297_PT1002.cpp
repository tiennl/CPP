#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	float a,b,c,p,s;
	cin>>a>>b>>c;
	if (a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a && abs(a-b)<c && abs(a-c)<b && abs(b-c)<a){
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<fixed<<setprecision(2)<<s;
	}
	else cout<<"No Solution";
	return 0;
}
