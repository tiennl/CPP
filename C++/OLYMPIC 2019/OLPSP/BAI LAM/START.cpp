#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	double vr,vt,s,tr,tt;
	cin>>vr>>vt>>s;
	s*=100;
	tr=s/vr;
	tt=s/vt;
	if (tr<=tt){
		cout<<-1;
		return 0;
	}	
	cout<<fixed<<setprecision(2)<<(tr-tt)/60;
	return 0;
}

