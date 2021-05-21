#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s,a,b;
	cin>>s;
	ll n=s.size();
	for (int k=1;k<n;k++)
		if (n%k==0){
			a=s.substr(0,k);
			sort(a.begin(),a.end());
			bool ok=true;
			for (int i=k;i<n;i+=k){
				b=s.substr(i,k);
				sort(b.begin(),b.end());
				if (a!=b){
					ok=false;
					break;
				}
			}
			if (ok){
				cout<<s.substr(0,k);
				return 0;
			}
		}
	cout<<-1;
	return 0;
}
