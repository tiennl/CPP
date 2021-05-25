#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define pb push_back 
#define N 20

int n,res=0;
string s="";
char a[N][N];
vector <string> r;

bool isPalin(string s){
	for (int i=0;i<=s.size()/2;i++)
		if (s[i]!=s[s.size()-i-1]) return false;
	return true;
}

void Try(string s, int i, int j){
	if (i==n-1 && j==n-1){
		s+=a[n-1][n-1];
		if (isPalin(s)) r.pb(s);
	}
	else{
		if (i<n-1) Try(s+a[i][j],i+1,j);
		if (j<n-1) Try(s+a[i][j],i,j+1);
	}
}

int main(){
	FIO
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) cin>>a[i][j];
	Try(s,0,0);
	sort(r.begin(),r.end());
	if (r.size()>0) res=1;
	for (int i=1;i<r.size();i++) 
		if (r[i]!=r[i-1]) res++;
	cout<<res;	
	return 0;
}

