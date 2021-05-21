#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll coun[5];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,res=0;
	string s;
	cin>>n;
	for (int i=0;i<5;i++) coun[i]=0;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s[0]=='M') coun[0]++;
		else if (s[0]=='A') coun[1]++;
		else if (s[0]=='R') coun[2]++;
		else if (s[0]=='C') coun[3]++;
		else if (s[0]=='H') coun[4]++;
	}
	for (int i=0;i<5;i++)
		for (int j=i+1;j<5;j++)
			for (int k=j+1;k<5;k++)
				res+=coun[i]*coun[j]*coun[k];
	cout<<res;
	return 0;
}
