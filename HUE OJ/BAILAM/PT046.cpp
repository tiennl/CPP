#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n,num;
	cin>>n;
	while (n--){
		cin>>num;
		if (num>=5 && num<=7) cout<<num<<" ";
	}	
	return 0;
}
