#include <bits/stdc++.h>
double a[10000000];
using namespace std;
int main(){
	unsigned long long t,n=0,pos=0;
	double num=0,x;
	cin>>t;
	for (int i=0;i<=60;i++)
		for (int j=0;j<=38;j++)
			for (int h=0;h<=26;h++){
				num=pow(2,i)*pow(3,j)*pow(5,h);
				if (num>0 && num<=1e18){
					n++;
					a[n]=num;
				}
			}
	sort(a+1,a+n+1);
	while (t--){
		cin>>x;
      	pos=0;
		pos=lower_bound(a+1,a+n+1,x)-a;
		if (x==a[pos]) cout<<pos<<endl;
		else cout<<"Not in sequence"<<endl;
	}
	return 0;
}
