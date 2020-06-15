#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	string s,st="";
	cin>>n;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
			st="";
			bool kt=0;
			for (int i=0;i<s.size();i++)
				if (s[i]>='a' && s[i]<='z') st+=s[i];
				else if (s[i]>='A' && s[i]<='Z') st+=char(s[i]+32);
			for (int i=0,j=st.size()-1;i<=st.size()/2;i++,j--)
				if (st[i]!=st[j]){
					cout<<"No"<<endl;
					kt=1;
					break;
				}
			if (kt==0) cout<<"Yes"<<endl;
		}
	}
	return 0;
}
