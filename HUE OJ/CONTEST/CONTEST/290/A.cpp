#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

char a[10][10];

int main(){
	FIO
	string s;
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++){
			cin>>a[i][j];
			s+=a[i][j];
		}
	if (s=="...k....k.k.k...k.k.k.k.k") cout<<"invalid";
	else cout<<"valid";
	return 0;
}
