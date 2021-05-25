#include <bits/stdc++.h>
using namespace std;
long long check[10000],a[100000];
int main(){
	long long n,res=0;
	string s;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s;
		for (int j='a';j<='z';j++) check[j]=0;
		for (int j=0;j<s.size();j++)
			if (check[s[j]]==0){
				a[s[j]]++;
				check[s[j]]=1;
			}
	}
	for (int i='a';i<='z';i++)
		if (a[i]==n) res++;
	cout<<res;
	return 0;
}
