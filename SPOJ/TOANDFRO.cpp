#include <bits/stdc++.h>
using namespace std;
#define ll long long 
char a[1000][1000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,col,row;
	string s;
	while (cin>>col){
		if (col==0) return 0;
		cin>>s;
		n=-1;
		row=s.size()/col;
		for (int i=0;i<row;i++){
			if (i%2==0)
				for (int j=0;j<col;j++){
					n++;
					a[i][j]=s[n];
				}
			else
				for (int j=col-1;j>=0;j--){
					n++;
					a[i][j]=s[n];
				}
		}
		for (int j=0;j<col;j++)
			for (int i=0;i<row;i++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
