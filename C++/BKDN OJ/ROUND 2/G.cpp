#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
string reverse(string s){
	string r="";
	for (int i=s.size()-1;i>=0;i--) r+=s[i];
	return r;
}
int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll k,p1=0,p2=0;
		cin>>k;
		string s,a,b;
		cin.ignore();
		getline(cin,s);
		getline(cin,a);
		getline(cin,b);
		p2=s.find(b);
		p1=reverse(s).find(reverse(a));
		if (p2==-1 || p1==-1) cout<<"NO"<<endl;
		else{
			p1=s.size()-a.size()-p1;
			p2+=(b.size()-1);
//			cout<<p1<<" "<<p2<<endl;
			if (p2-p1+1<=a.size()+b.size()+k && p1<=p2){
				int kt=0;
				for (int i=p1;i<=p2;i++) 
					if (!(s[i]>='a' && s[i]<='z')){
						kt=-1;
						cout<<"NO"<<endl;
						break;
					}
				if (kt==0) cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		} 
	}
	return 0;
}
