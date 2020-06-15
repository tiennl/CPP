#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	float n,m,p,s;
	ll res=0;
	cin>>n>>m>>p;
	s=n;
	while (s<p){
		s+=s*(m/100);
		res++;
	}	
	cout<<res;
	return 0;
}
