#include <bits/stdc++.h>
using namespace std;
int main(){
	double n,a,b,maxx;
	cin>>n;
	maxx=(long long)((sqrt(n*8+1)+1)/2);
	for (int i=0;i<=maxx;i++){
		b=(double)i;
		a=n/(b+1)-(b/2);
		if ((long long)a==a && (long long)b==b && a>=0 && b>0)
			cout<<(long long)a<<" "<<(long long)(a+b)<<endl;
	}
	return 0;
}
