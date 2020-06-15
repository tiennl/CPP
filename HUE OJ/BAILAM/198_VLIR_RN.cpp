#include <bits/stdc++.h>
int a[7];
using namespace std;
int main(){
	long long t,res=0;
	string s;
	a['I']=1;
	a['V']=5;
	a['X']=10;
	a['L']=50;
	a['C']=100;
	a['D']=500;
	a['M']=1000;
	cin>>t;
	while (t--){
		cin>>s;
		res=0;
		for (int i=0;i<s.size();i++){
			if (a[s[i]]>=a[s[i+1]]) {
				res+=a[s[i]];
			}
			else{
				res+=a[s[i+1]];
				res-=a[s[i]];
				i++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
