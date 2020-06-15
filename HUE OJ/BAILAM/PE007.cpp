#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull unsigned long long 
#define N 1000005

int main(){
	FIO
	ull t,n,res=0,uc=0;
	cin>>t;
	while (t--){
		cin>>n;
		res=n*n*3;
		for (int x=1;x<=n;x++)
    		for (int y=1;y<=n;y++){
    			uc=__gcd(x,y);
        		res+=(min(y*uc/x,(n-x)*uc/y)*2);
        	}
		cout<<res<<endl;
	}
	return 0;
}
