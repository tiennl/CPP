#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
char a[10][10],b[10][10];
int main(){
	FIO
	ll res=0;
	char ch='A';
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++){
			a[i][j]=ch;
			ch++;
		}
	a[4][4]='.';
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++){
			cin>>b[i][j];
			if (a[i][j]!=b[i][j] && b[i][j]!='.'){
				for (int ii=0;ii<4;ii++)
					for (int jj=0;jj<4;jj++)
						if (a[ii][jj]==b[i][j]){
							res+=abs(ii-i)+abs(jj-j);
							break;
						}
			}
		}
	cout<<res;
	return 0;
}
