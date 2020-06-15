#include <bits/stdc++.h>
using namespace std;
bool armstrong(long long x){
	long long scs=0,m,s=0;
	m=x;
	while (m>0){
		scs++;
		m/=10;
	}
	m=x;
	while (m>0){
		s+=pow(m%10,scs);
		m/=10;
	}
	if (s==x) return true;
	return false;
}
int main(){
	long long n,k=0,num;
	cin>>n;
	num=-1;
	while (k<n){
		num++;
		if (armstrong(num)){
			k++;
			cout<<num<<" ";
		}
	}
	return 0;
}
