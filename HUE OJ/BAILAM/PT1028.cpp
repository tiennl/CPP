#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	string s;
	cin>>n;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
		if (s[0]>='A' && s[0]<='Z') cout<<(char)(s[0]+32);
		else cout<<(char)s[0];
		for (int i=1;i<s.size();i++){
			if (s[i-1]==' ')
				if (s[i]>='A' && s[i]<='Z') cout<<(char)(s[i]+32);
				else cout<<(char)s[i];
		}
		for (int i=s.size()-1;i>=0;i--)
			if (s[i-1]==' '){
				for (int j=i+1;j<s.size();j++)
					if (s[j]>='A' && s[j]<='Z') cout<<(char)(s[j]+32);
					else cout<<(char)s[j];
					break;
			}
		 cout<<"@huscmail.edu.vn"<<endl;}
	}
	return 0;
}
