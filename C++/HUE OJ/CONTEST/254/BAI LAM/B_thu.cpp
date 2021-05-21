#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
int main(){
	FIO
	ll sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	for (int i=0;i<tx-sx;i++) cout<<'R';
	for (int i=0;i<ty-sy;i++) cout<<'U';
	for (int i=0;i<tx-sx;i++) cout<<'L';
	for (int i=0;i<ty-sy+1;i++) cout<<'D';
	for (int i=0;i<tx-sx+1;i++) cout<<'R';
	for (int i=0;i<ty-sy+1;i++) cout<<'U';
	cout<<'L';
	cout<<'U';
	for (int i=0;i<tx-sx+1;i++) cout<<'L';
	for (int i=0;i<ty-sy+1;i++) cout<<'D';
	cout<<'R';
	return 0;
}
