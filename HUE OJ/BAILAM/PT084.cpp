#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	getline(cin,s);
	ll d=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='/') d++;
		if (d==0) cout<<s[i];
		if (d==2) d=0;
	}	
	return 0;
}
