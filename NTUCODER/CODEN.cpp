#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005
int main(){
	FIO
	ll m,n;
	cin>>m>>n;
	cout<<(m/2+m%2)*(n/2+n%2);
	return 0;
}
