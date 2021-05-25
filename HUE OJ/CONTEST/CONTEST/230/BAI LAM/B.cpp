#include <bits/stdc++.h>
using namespace std;
int main(){
	string s,st;
	while (cin>>s){
		st=s;
		next_permutation(st.begin(),st.end());
		// next_permutation(all(s));
		if (s>=st) cout<<"no answer"<<endl;
		else cout<<st<<endl;
	}
	return 0;
}
