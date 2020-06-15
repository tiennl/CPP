#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,res=0,l=0;
	string s;
	cin>>n;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
			res=0;
			l=0;
			for (int i=0;i<s.size();i++)
				if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==39)
					l++;
				else{
					res=max(res,l);
					l=0;
				}
			cout<<res<<endl;
		}
	}
	return 0;
}
