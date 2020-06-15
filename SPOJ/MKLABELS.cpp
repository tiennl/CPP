#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,tc=0;
	while (cin>>n){
		tc++;
		if (n==0) return 0;
		cout<<"Case "<<tc<<", N = "<<n<<", # of different labelings = ";
		cout<<(ll)pow(n,n-2)<<endl;
	}
	return 0;
}
