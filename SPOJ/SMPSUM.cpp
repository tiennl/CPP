#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,res=0;
	cin>>a>>b;
	for (int i=a;i<=b;i++) res+=i*i;
	cout<<res;
	return 0;
}
