#include <bits/stdc++.h>
#include <string>
using namespace std;
long long doistring(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}
int main(){
	int t;
	long long res=0;
	string n;
	cin>>n;
	for (int i=0;i<n.size();i++)
		res+=pow((int)(n[i]-48),i+1);
	if (res==doistring(n)) cout<<"YES";
	else cout<<"NO";
	return 0;
}
