#include <bits/stdc++.h>
long long a[10000];
using namespace std;
int main(){
	long long n;
	double ans=0,res=0,d=0,s1=0,s2=0,size=0,pi=2*acos(0.0);
	string s;
	for (int i='A',j=1;i<='Z';i++,j++) a[i]=j;
	for (int i='a',j=1;i<='z';i++,j++) a[i]=j;
	a[' ']=27;
	a[39]=28;
	cin>>n;
	n++;
	while (n--){
		getline(cin,s);
		size=s.size();
		res=0;
		ans=0;
		
		ans=res*(pi/7)+size;
		cout<<fixed<<setprecision(4)<<ans<<endl;
	}
	return 0;
}
