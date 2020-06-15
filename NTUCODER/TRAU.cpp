#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,res=0;
	cin>>n>>m;
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			for (int c=1;c<=n;c++)
				if (a+b+c==n && a*5+b*3+c/3==m && c%3==0){
					cout<<a<<" "<<b<<" "<<c;
					return 0;
				}	
	cout<<-1;
	return 0;
}
