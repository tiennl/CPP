#include <bits/stdc++.h>
using namespace std;
int uoc_chung(int x, int y){
	for (int i=x;i>=1;i--)
		if (x%i==0 && y%i==0)
			return i;
	return 0;
}
int main(){
	string s,t;
	cin>>s>>t;
	if (s.size()<t.size()) swap(s,t);
	if (s.size()%t.size()==0) cout<<t;
	else if (uoc_chung(s.size(),t.size())>=1)
			for (int i=1;i<=uoc_chung(s.size(),t.size());i++) cout<<1;
	else cout<<1;
	return 0;
}
