#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll coun[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	cin>>s;
	ll sum=0;
	for(int i=0;i<s.size();i++) coun[s[i]]++;
	for(int i='a';i<='z';i++)
		sum+=coun[i]*(coun[i]-1)/2;
	cout<<s.size()*(s.size()-1)/2-sum+1;
	return 0;
}
