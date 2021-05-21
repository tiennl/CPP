#include <bits/stdc++.h>
using namespace std;
#define ll long long 	
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m;
	string s;
	cin>>n;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
			while (s[0]==' ') s.erase(0,1);
			while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
			for (int i=0;i<s.size();i++)
				if (s[i]==' ' && s[i+1]==' '){
					s.erase(i,1);
					i--;
				} 
			cout<<s<<endl;
		}
	}
	return 0;
}
