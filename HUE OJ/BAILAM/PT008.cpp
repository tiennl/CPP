#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	float a,b,c,d;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	cout<<fixed<<setprecision(4);
	if (d<0) cout<<"No solution";
//	else if (d==0) cout<<-b/(2*a)<<endl<<-b/(2*a);
	else cout<<(-b+sqrt(d))/(2*a)<<endl<<(-b-sqrt(d))/(2*a);	
	return 0;
}
