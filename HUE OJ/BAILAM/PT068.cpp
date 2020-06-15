#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[N];

int main(){
	FIO
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++) a[s[i]]=1;
	for (int i='a';i<='z';i++)
		if (a[i]==0){
			cout<<(char)i;
			return 0;
		}
	cout<<"None";
	return 0;
}
