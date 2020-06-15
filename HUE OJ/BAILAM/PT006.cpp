#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll x,y;
	cin>>x>>y;
	if (x==0 && y==0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies at the origin.";	
	else if (x>=0 && y>=0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the I quandrant.";	
	else if (x<=0 && y>=0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the II quandrant.";
	else if (x<=0 && y<=0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the III quandrant.";
	else cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the IV quandrant.";
	return 0;
}
