#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]==',') cout<<" ";
		else cout<<s[i];	
	return 0;
}
