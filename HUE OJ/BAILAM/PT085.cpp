#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	string a,b;
	cin>>a>>b;
	for (int i=0;i<max(a.size(),b.size());i++){
		if (i<a.size()) cout<<a[i];
		if (i<b.size()) cout<<b[i];
	}	
	return 0;
}
