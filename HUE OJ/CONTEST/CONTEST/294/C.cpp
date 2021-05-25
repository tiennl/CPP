#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 100005

string a[N];
set <string> s;

int main(){
	FIO
	ll n,coun=0,res;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	res=n;
	for (int i=0;i<n;i++){
		coun=1;
		set <string> ss;
		ss.insert(a[i]);
		for (int j=i+1;j<n;j++){
			coun++;
			ss.insert(a[j]);
			if (ss.size()==s.size()){
				res=min(res,coun);
				break;
			}
		}
	}
	cout<<res;
	return 0;
}
