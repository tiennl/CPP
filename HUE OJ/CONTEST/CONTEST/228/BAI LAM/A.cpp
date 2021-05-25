#include <bits/stdc++.h>
using namespace std;
int main(){
	int s=0,n=0,e=0,w=0;
	string st;
	cin>>st;
	for (int i=0;i<st.size();i++)
		if (st[i]=='S') s++;
		else if (st[i]=='N') n++;
		else if (st[i]=='E') e++;
		else w++;
	if (((s>0 && n>0) || (s==0 && n==0)) && ((e>0 && w>0) || (e==0 && w==0))) 
		cout<<"Yes";
	else cout<<"No";
	return 0;
}
