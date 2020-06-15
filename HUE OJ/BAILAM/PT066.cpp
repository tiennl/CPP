#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string s;
	while (cin>>s){
		ll up=0,lower=0;
		for (int i=0;i<s.size();i++)
			if (s[i]>='A' && s[i]<='Z') up++;
			else lower++;
		if (up>lower){
			for (int i=0;i<s.size();i++)
				if (s[i]>='a' && s[i]<='z') cout<<(char)(s[i]-32);
				else cout<<s[i];
		}
		else{
			for (int i=0;i<s.size();i++)
				if (s[i]>='A' && s[i]<='Z') cout<<(char)(s[i]+32);
				else cout<<s[i];	
		}
		cout<<endl;
	}
	return 0;
}
