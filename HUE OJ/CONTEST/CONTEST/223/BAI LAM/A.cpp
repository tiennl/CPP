#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	if (a<=0 && b>=0) cout<<"Zero";
	else if (a>0) cout<<"Positive";
	else if (b<0){
		if ((b-a+1)%2==0) cout<<"Positive";
		else cout<<"Negative";
	}
	else{
		if ((0-a+1)%2==0) cout<<"Positive";
		else cout<<"Negative";
	}
	return 0;
}
