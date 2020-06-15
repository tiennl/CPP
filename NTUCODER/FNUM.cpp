#include <bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
inline std::string tostring(const T& x){
	std::ostringstream o;
	o << x;
	return o.str();
}
string sum(string s){
	ll r=0;
	string rr="";
	for (int i=0;i<s.size();i++) r+=(s[i]-'0');
	rr=tostring(r);
	return rr;
} 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll res=0;
	cin>>s;
	s=sum(s);
	if (s.size()<2){
		cout<<s;
		return 0;
	}
	while (s.size()>1){
		s=sum(s);
		if (s.size()<2){
			cout<<s;
			return 0;
		}
	}
	return 0;
}
