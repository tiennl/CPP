#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t;
	float a1,b1,c1,a2,b2,c2,d,dx,dy;
	cin>>t;
	while (t--){
		cin>>a1>>b1>>c1>>a2>>b2>>c2;
		d=a1*b2-a2*b1;
		dx=c1*b2-c2*b1;
		dy=a1*c2-a2*c1;
		if (d==0){
			if (c1==c2) cout<<"many solution"<<endl;
			else cout<<"no solution"<<endl;
		} 
		else{
			cout<<fixed<<setprecision(2)<<dx/d<<" "<<dy/d<<endl;
		}
	}
	return 0;
}

