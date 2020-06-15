#include <bits/stdc++.h>
long long a[1000];
using namespace std;
int main(){
	long long t,res=0,so=0;
	string s;
	cin>>t;
	while (t--){
		cin>>s;
		res=0;
		for (int i=100;i<=999;i++) a[i]=0;
		for (int i=0;i<s.size()-2;i++){
			so=0;
			so=(int)(s[i]-48)*100+(int)(s[i+1]-48)*10+(int)(s[i+2]-48);
			if (a[so]==0 && s[i]!='0') res++;
			a[so]++;
		}
		cout<<res<<endl;
	}
	return 0;
}
