#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,a,mu=2,res=0;
	cin>>t;
	while (t--){
		cin>>a;
		res=0;
		if (a==0) cout<<0<<endl;
		else if (a==1 || a==-1) cout<<1<<endl;
		else if (a>0) {
			mu=0;
			while ((pow(a,mu))<=10e17){
				mu++;
			}
			res=pow(a,mu-1);
			cout<<res<<endl;
		}
		else if (a<0){
			mu=0;
			while ((pow(a,mu))<=10e17){
				mu+=2;
			}
			res=pow(a,mu-2);
			cout<<res<<endl;
		}
	}
	return 0;
}
