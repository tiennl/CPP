#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define pb push_back
#define N 1000005

vector <ll> a,b;

int main(){
	FIO
	ll n,s=0,s1=0,s2=0,st;
	cin>>n;	
	s=n*(n+1)/2;
	st=s/2;
	for (int i=n;i>0;i--){
		if (st-i>=0){
			a.pb(i);
			s1+=i;
			st-=i;
		} 
		else{
			b.pb(i);
			s2+=i;
		}
	}
	if (s1==s2){
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		cout<<"YES"<<endl<<a.size()<<endl;
		for (int i=0;i<a.size();i++) cout<<a[i]<<" ";
		cout<<endl<<b.size()<<endl;
		for (int i=0;i<b.size();i++) cout<<b[i]<<" ";
	}
	else cout<<"NO";
	return 0;
}
