#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	float a,b,c;
	cin>>a>>b>>c;
	if (a==b && b==c && c==a) cout<<"Tam giac deu";
	else if (a==b || b==c || c==a) cout<<"Tam giac can";
	else cout<<"Tam giac thuong";	
	return 0;
}
