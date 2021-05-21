#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,num,maxa=0,gcd=0,sl=0;
	cin>>t;
	while (t--){
		cin>>n;
		maxa=0;
		gcd=0;
		sl=0;
		for (int i=0;i<n;i++){
			cin>>num;
			maxa=max(maxa,num);
			gcd=__gcd(gcd,num);
		}
		sl=maxa/gcd-n;
		if (sl%2==0) cout<<"M"<<endl;
		else cout<<"DD"<<endl;
	}
	return 0;
}
