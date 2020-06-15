#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long res=0;
	string n;
	cin>>t;
	while (t--){
		cin>>n;
		res=0;
		for (int i=0;i<n.size();i++)
			if (((int)(n[i]-48))%2==0) res+=(int)(n[i]-48);
		cout<<res<<endl;
	}
	return 0;
}
