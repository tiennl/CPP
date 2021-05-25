#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
char a[100][100];
int main(){
	FIO
	ll n,m,d;
	string st="",s="";
	char c;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) cin>>a[i][j];
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++){
			cin>>c;
			s+=c;
		}
	for (int i=0;i<n-m+1;i++)
		for (int j=0;j<n-m+1;j++){
			st="";
			for (int i1=i;i1<i+m;i1++)
				for (int j1=j;j1<j+m;j1++)
					st+=a[i1][j1];
			if (st==s){
				cout<<"Yes";
				return 0;
			}
		}
	cout<<"No";
	return 0;
}
