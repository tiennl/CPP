#include <bits/stdc++.h>
bool prime[1000000];
using namespace std;
bool isDX(long long x){
	long long dao=0,y=0;
	y=x;
	while (y>0){
		dao=dao*10+(y%10);
		y/=10;
	}
	if (dao==x) return true;
	return false;
}
int main(){
	long long t,a,b,m=1e5,res=0;
	cin>>t;
	for (int i=2;i<=m;i++) prime[i]=true;
	for (int p=2;p*p<=m;p++)  
        if (prime[p])
            for (int i=p*2;i<=m;i+=p) prime[i]=false;
	while (t--){
		cin>>a>>b;
		res=0;
		for (int i=a;i<=b;i++)
			if (prime[i] && isDX(i)) res++;
		cout<<res<<endl;
	}	 
	return 0;
}
