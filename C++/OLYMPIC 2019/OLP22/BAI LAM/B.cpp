#include <bits/stdc++.h>
int a[10000];
using namespace std;
int main(){
	long long n,m=0;
	double ans=0,res=0,d=0,s1=0,s2=0,size=0,pi=2*acos(0.0);
	string s;
	for (int i='A',j=1;i<='Z';i++,j++) a[i]=j;
	for (int i='a',j=1;i<='z';i++,j++) a[i]=j;
	cin>>n;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
		size=s.size();
		res=0;
		ans=0;
		s1=0;
		s2=0;
		d=0;
		for (int i=0;i<size-1;i++){
			if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) s1=a[s[i]];
			else if (s[i]==' ') s1=27;
			else s1=28;
			if ((s[i+1]>='A' && s[i+1]<='Z') || (s[i+1]>='a' && s[i+1]<='z')) s2=a[s[i+1]];
			else if (s[i+1]==' ') s2=27;
			else s2=28;
			d=abs(s1-s2);
			res+=min(d,28-d);
		}
		ans=res*(pi/7)+size;
		cout<<fixed<<setprecision(4)<<ans<<endl;
		}
	}
	return 0;
}
