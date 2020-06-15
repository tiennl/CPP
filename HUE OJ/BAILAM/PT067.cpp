#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	while (getline(cin,s)){
		while (s[0]==' ') s.erase(0,1);
		while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
		while (s.find("  ")!=-1) s.erase(s.find("  "),1);
		cout<<s<<endl;
	}	
	return 0;
}
