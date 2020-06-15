#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	string s="";
	cin>>n;
	for (int i=1;i<=n;i++){
		if (i%2!=0) s="1"+s;
		else s="0"+s;
		cout<<s<<endl;
	}
	return 0;
}
