#include <bits/stdc++.h>
long long a[100];
using namespace std;
int main(){
	long long t,count1=0,count2=0,res=0;
	string s;
	cin>>t;
	while (t--){
		cin>>s;
		count1=0;
		count2=0;
		res=0;
		for (int i='a';i<='z';i++) a[i]=0;
		for (int i=0;i<s.size();i++) a[s[i]]++;
		for (int i='a';i<='z';i++)
			if (a[i]%2==0) count2+=a[i];
			else if (a[i]%2!=0 && a[i]>0) count2+=(a[i]-1),count1=1;
		if (count1>0) res++;
		res+=count2;
		cout<<res<<endl;
	}
	return 0;
}
