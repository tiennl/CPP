#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

string reverse(string s){
	string res="";
	for (int i=s.size()-1;i>=0;i--) res+=s[i];
	return res;
}

ll solve(string s){
	ll res=0;
	for (int i=0;i<s.size()/2;i++){
		ll l=i;
		ll r=s.size()-l-1;
		while (l<r){
			if (s[l]==s[r]) break;
			else r--;
		}
		if (l==r) return -1;
		for (int j=r;j<s.size()-l-1;j++){
			swap(s[j],s[j+1]);
			res++;
		}
	}
	return res;
}

int main(){
	FIO
	string s;
	cin>>s;
	if (solve(s)==-1){
		if (solve(reverse(s))>-1) cout<<solve(reverse(s));
		else cout<<-1;
	}
	else cout<<solve(s);
	return 0;
}
