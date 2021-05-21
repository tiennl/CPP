#include <bits/stdc++.h>
bool prime[10000000];
using namespace std;
int main(){
	long long n,a,b,m=1e7;
	double sum=0,coun=0;
	cin>>n;
	for (int i=2;i<=m;i++) prime[i]=true;
	for (int p=2;p*p<=m;p++)  
        if (prime[p])
            for (int i=p*2;i<=m;i+=p) prime[i]=false; 
	while (n--){
		cin>>a>>b;
		sum=0;
		coun=0;
		for (int i=a;i<=b;i++)
			if (prime[i]) sum+=i,coun++;
		if (coun==0) cout<<"0.00"<<endl;
		else cout<<fixed<<setprecision(2)<<sum/coun<<endl;
	}
	return 0;
}
