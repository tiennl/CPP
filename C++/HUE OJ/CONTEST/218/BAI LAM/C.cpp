#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	if (x==0 && y==0) cout<<"The coordinate point (0, 0) lies at the origin.";
	else if (x>0 && y>0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the I quandrant.";
	else if (x<0 && y>0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the II quandrant.";
	else if (x<0 && y<0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the III quandrant.";
	else if (x>0 && y<0) cout<<"The coordinate point ("<<x<<", "<<y<<") lies in the IV quandrant.";
	return 0;
}
