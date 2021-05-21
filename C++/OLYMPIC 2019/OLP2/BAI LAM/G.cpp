#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,res="",ahi="";
	int d,pos;
	bool ok=0;
	cin>>s;
	for (int i=s.size();i>0;i--)
		if (s.size()%i==0){
			res="";
			d=0;
			pos=s.size()/i;
			for (int j=0;j<pos;j++) res+=s[j];
			for (int j=pos;j<s.size();j+=pos){
				ahi="";
				for (int k=j;k<j+res.size();k++) ahi+=s[k];
				if (ahi==res) d++;
				else break;
			}
			if (d==i-1){
				cout<<i<<res;
				return 0;
			}		
		}
	return 0;
}

