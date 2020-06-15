#include <bits/stdc++.h>
using namespace std;
long long stol(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}
int main(){
	int t,m;
	long long res=0,cong=0,tru=0;
	string st,s,so="";
	cin>>t;
	m=t;
	t++;
	while (t--){
		getline(cin,st);
		if (t!=m){
		res=0;
		so="";
		s="";
		for (int i=0;i<st.size();i++)
			if (st[i]!=' ') s+=st[i];
		st=s;
		s="";
		for (int i=0;i<st.size();i++)
			if (st[i]=='+' || st[i]=='-'){
				cong=0;
				tru=0;
				for (int j=i;j<st.size();j++)
					if (st[j]=='+') cong++;
						else if (st[j]=='-') tru++;
							else{
								if (tru%2==0) s+="+";
								else s+="-";
								break;
							}
				i+=(cong+tru-1);
			}
			else s+=st[i];
	//	cout<<s<<endl;
		for (int i=0;i<s.size();i++)
			if (s[i]!=' '){
				if (s[i]!='-') s="+"+s;
				break;
			}
		for (int i=0;i<s.size();i++)
			if (s[i]=='+'){
				for (int j=i+1;j<s.size();j++)
					if (s[j]>='0' && s[j]<='9')
						so+=s[j];
					else if (s[j]=='+' || s[j]=='-') break;
				res+=stol(so);
				so="";
			}
			else if (s[i]=='-'){
				for (int j=i+1;j<s.size();j++)
					if (s[j]>='0' && s[j]<='9')
						so+=s[j];
					else if (s[j]=='+' || s[j]=='-') break;
				res-=stol(so);
				so="";
			}
		cout<<res<<endl;
	}
	}
	return 0;
}
