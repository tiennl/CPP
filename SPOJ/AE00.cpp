#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,res=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (i*j<=n) res++;
	cout<<res;
	return 0;
}
