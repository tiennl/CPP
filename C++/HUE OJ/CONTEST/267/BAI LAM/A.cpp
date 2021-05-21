#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 

int main(){
	FIO
	ll s=0,n=0,e=0,w=0;
	string st;
	cin>>st;
	for (int i=0;i<st.size();i++)
		if (st[i]=='S') s++;
		else if (st[i]=='N') n++;
		else if (st[i]=='E') e++;
		else w++;
	if ((s>0 && n==0) || (s==0 && n>0) || (e>0 && w==0) || (e==0 && w>0)){
		cout<<"No";
		return 0;
	}	
	cout<<"Yes";
	return 0;
}
