#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	string s;
	cin>>n;
	while (n--){
		cin>>s;
		int up=0,lower=0;
		for (int i=0;i<s.size();i++)
			if (s[i]>='a' && s[i]<='z') lower++;
			else up++;
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
