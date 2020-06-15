#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,k,num;
	string s;
	cin>>n>>k;
	while (getline(cin,s)){
		for (int i=0;i<s.size();i++)
			if (s[i]>='A' && s[i]<='Z'){
				num=s[i]+k;
				if (num<='Z') cout<<char(num);
				else cout<<char(num-26); 
			}
			else cout<<s[i];
		cout<<endl;	
	}	
	return 0;
}
