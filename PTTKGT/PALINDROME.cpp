// Minimum characters delete to make palindrome

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 1005

string s;
ll d[N][N];

ll minDel(ll i, ll j){
	if (i>=j) return 0;
	if (s[i]==s[j]) return minDel(i+1,j-1);
	return 1+min(minDel(i+1,j),minDel(i,j-1));
}

int main(){
	cin>>s;
	cout<<minDel(0,s.size()-1)<<endl;
	// Khu de quy
	memset(d,0,sizeof(d));
	for (int i=s.size()-1;i>=0;i--)
		for (int j=i+1;j<s.size();j++)
		if (s[i]==s[j]) d[i][j]=d[i+1][j-1];
			else d[i][j]=1+min(d[i][j-1],d[i+1][j]);
	cout<<d[0][s.size()-1];
	return 0;
}
