#include <bits/stdc++.h>
#include <iomanip>
typedef long long ll;
float a[10000000];
using namespace std;
int main(){
	unsigned long long n,p;
	float sum=0,res=0,x;
	char s;
	cin>>n;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	while (cin>>s){
		if (s=='i'){
			cin>>x>>p;
			if (p>=1 && p<=n){
				for (ll i=n+1;i>p;i--) a[i]=a[i-1];
				a[p]=x;
			}
			else a[n+1]=x;
			n++;
			sum+=x;
		}
		else if (s=='d'){
			cin>>p;
			if (p>=1 && p<=n){
				sum-=a[p];
				for (ll i=p;i<=n;i++) a[i]=a[i+1];
				n--;
			}
		}
		else if (s=='a'){
			if (n<=0) cout<<"0.0000"<<endl;
			else{
				res=sum/(double)n;
				cout<<fixed<<setprecision(4)<<res<<endl;
			}
		}
		else if (s=='0'){
			cin>>x;
			break;
		}
	}
	return 0;
}
