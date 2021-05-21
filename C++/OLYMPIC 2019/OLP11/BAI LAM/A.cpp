#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c=0;
	cin>>a>>b;
	if (a<=0 && b>=0) cout<<"Zero";
	else if (a>0) cout<<"Positive";
	else{
		c=abs(b)-abs(a);
		if (c%2!=0) cout<<"Positive";
		else if (c%2==0) cout<<"Negative";
	}
	return 0;
}
