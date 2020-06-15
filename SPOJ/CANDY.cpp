#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,res=0,sum=0;
	while (cin>>n){
		res=0;
		sum=0;
		if (n!=-1){
			for (int i=0;i<n;i++) cin>>a[i],sum+=a[i];
			if (sum%n!=0) cout<<-1<<endl;
			else{
				sum/=n;
				for (int i=0;i<n;i++) 
					if (a[i]>sum) res+=(a[i]-sum);
				cout<<res<<endl;
			}
		}
		else break;
	}
	return 0;
}
