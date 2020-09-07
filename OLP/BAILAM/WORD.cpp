#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 10005

string a[N];

int main(){
	FIO
	ll n,m;
	string s;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for (int i=0;i<m;i++){
		cin>>s;
		int ok=0;
		for (int j=0;j<n;j++)
			if (s==a[j]){
				cout<<"YES"<<endl;
				ok=1;
				break;
			}
		if (ok==0) cout<<"NO"<<endl;
	}
	return 0;
}
