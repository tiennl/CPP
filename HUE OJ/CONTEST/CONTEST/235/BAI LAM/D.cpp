#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	string s;
	cin>>n;
	while (n--){
		cin>>s;
		int up=0;
		for (int i=0;i<s.size();i++)
			if (s[i]>='A' && s[i]<='Z') up++;
		cout<<up+1<<endl;
	}
	return 0;
}
