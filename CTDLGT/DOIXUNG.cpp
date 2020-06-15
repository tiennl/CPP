#include <iostream>
using namespace std;
bool doixung(string s,long long l,long long r){
	if (l<r)
	{
		if (s[l]!=s[r]) return 0;
		else return doixung(s,l+1,r-1);
	}
	return 1;
}
int main(){
	string s;
	cin>>s;
	if (doixung(s,0,s.size()-1)) cout<<"YES";
	else cout<<"NO";
	return 0;
}

