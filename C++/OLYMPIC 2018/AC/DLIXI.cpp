#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c,res=0;
	cin>>a>>b>>c;
	for (int i=a;i<=b;i++)
		if (i%c==0) res++;
	cout<<res;
	return 0;
}

