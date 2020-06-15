#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	string s;
	cin>>n;
	n++;
	while (n--){
		getline(cin,s);
		if (s[0]>='a' && s[0]<='z') cout<<(char)(s[0]-32);
		else cout<<(char)s[0];
		for (int i=1;i<s.size();i++){
			if (s[i]==' ') cout<<" ";
			else if (s[i-1]==' ')
				if (s[i]>='a' && s[i]<='z') cout<<(char)(s[i]-32);
				else cout<<(char)s[i];
			else
				if (s[i]>='A' && s[i]<='Z') cout<<(char)(s[i]+32);
				else cout<<(char)s[i];
		}
		cout<<endl;
	}
	return 0;
}
