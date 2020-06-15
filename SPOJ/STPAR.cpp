#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pb push_back
#define N 1000005
int main(){
	FIO
	ll n;
	while (cin>>n){
		if (n==0) return 0;
		ll num,ok=1;
		stack <ll> s;
		vector <ll> v;
		for (int i=0;i<n;i++){
			cin>>num;
			while (s.size() && s.top()<num){
				v.pb(s.top());
				s.pop();
			}
			s.push(num);
		}
		while (s.size()){
			v.pb(s.top());
			s.pop();
		}
		for (int i=0;i<v.size();i++)
			if (v[i]!=i+1){
				ok=0;
				break;
			}
		if (ok) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
