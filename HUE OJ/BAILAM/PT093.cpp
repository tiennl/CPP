#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	while (cin>>s){
		ll res=1;
		for (int i=1;i<s.size();i++)
			if (s[i]>='A' && s[i]<='Z') res++;
		cout<<res<<endl;
	}	
	return 0;
}
