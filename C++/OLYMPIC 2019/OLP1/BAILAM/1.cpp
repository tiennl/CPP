#include <bits/stdc++.h>
using namespace std;
long long uoc(long long a, long long b){
	long long r;
	while (b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	long long s,t;
	cin>>s>>t;
	cout<<uoc(s,t);
	return 0;
}

//6 4
