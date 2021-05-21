#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,k,num;
	string s;
	cin>>n>>k;
	m=n;
	n++;
	while (n--){
		getline(cin,s);
		if (n!=m){
			for (int i=0;i<s.size();i++)
				if (s[i]>='A' && s[i]<='Z'){
					num=s[i]+k;
					if (num<='Z') cout<<char(num);
					else cout<<char(num-26); 
				}
				else cout<<s[i];
			cout<<endl;
		}
	}	
	return 0;
}
