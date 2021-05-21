#include <bits/stdc++.h>
using namespace std;
int main(){
	long long q,n,maxx=0,res1=0,res2=0,x=0,y=0;
	long long m=0;
	cin>>q;
	for (int i=0;i<q;i++){
		cin>>n;
		m=n*n+1;
		maxx=0;
		res1=0;
		res2=0;
		x=0;
		y=0;
		for (int s1=2;s1<=sqrt(m)+1;s1++){
			if (m%s1==0){
				x=s1-1;
				y=m/s1-1;
				if (x+y>maxx && x<=y){
					res1=x;
					res2=y;
					maxx=x+y;
				}
				//cout<<x<<" "<<y<<endl;
			}
		}
		cout<<res1<<res2<<endl;
	}
	return 0;
}
