#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	ll pa=0,pz=0;
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]=='A'){
			pa=i;
			for (int j=s.size()-1;j>pa;j--)
				if (s[j]=='Z'){
					pz=j;
					cout<<pz-pa+1;
					return 0;
		}
	}
	return 0;
}
