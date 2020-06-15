#include <bits/stdc++.h>
long long a[500];
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
			bool kt=0;
			for (int i='A';i<='Z';i++) a[i]=0;
			for (int i='a';i<='z';i++) a[i]=0;
			for (int i=0;i<s.size();i++) a[s[i]]++;
			for (int i='A';i<='Z';i++)
				if (a[i]==0 && a[i+32]==0){
					kt=1;
					break;
				} 
			if (kt==1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}
