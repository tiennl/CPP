#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,g=0,c=0;
	cin>>n>>m;
	c=(m-2*n)/2;
	g=n-c;
	if(g<0 || c<0 || m%2!=0)
		cout<<-1;
	else cout<<g<<" "<<c;
	return 0;
}
