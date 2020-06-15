#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll m,res=0;
	string s,ss,st="";
	cin>>m>>s;
	for (int i=0;i<s.size();i++){
		ss=s,st=ss[0];
		for (int j=1;j<m;j++){
			st+=ss[j];
			cout<<st<<endl;
			while (ss.find(st)==0) ss.erase(0,j);
			if (ss==""){
				cout<<st;
				return 0;
			}
		}
	}	
	return 0;
}
