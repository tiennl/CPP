#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
char a[500][500];
int main(){
	FIO
	ll m,n,k;
	cin>>m>>n>>k;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	for (int i=0;i<m;i++){
		for (int h=0;h<k;h++){
			for (int j=0;j<n;j++)
				for (int hh=0;hh<k;hh++) cout<<a[i][j];
			cout<<endl;
		}
	}	
	return 0;
}
