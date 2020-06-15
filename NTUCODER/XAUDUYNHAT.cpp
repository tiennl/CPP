#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	int res=0;
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++){
		set <char> ss;
		for (int j=i;j<s.size();j++){
			if (s[i]>='A' && s[i]<='Z') ss.insert(s[j]+32);
			else ss.insert(s[j]);
			if (ss.size()==j-i+1) res=max(res,j-i+1);
			else break;
		}
	}
	cout<<res;
	return 0;
}
