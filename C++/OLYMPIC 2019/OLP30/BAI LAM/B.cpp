#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll f[10000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k=0;
	string s,res="";
	cin>>n>>s;
	for (int i=0;i<26;i++) cin>>f[i];
	for (int i=0;i<s.size();i++) 
		if (s[i]>='a' && s[i]<='z'){
			f[s[i]-'a']--;
			if (f[s[i]-'a']<0){
				cout<<-1;
				return 0;
			}
		}
	for (int i=0;i<s.size();i++)
		if (s[i]!='?') res+=s[i];
		else{
			while (f[k]==0 && k<26) k++;
			if (f[k]>0 && k<26){
				f[k]--;
				res+=(char)(k+'a');
			}
			else{
				cout<<-1;
				return 0;
			}
		}	
	cout<<res;
	return 0;
}
