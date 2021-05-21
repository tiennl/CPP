#include <bits/stdc++.h>
using namespace std;
void change(int n, int &k, int &a, int &b, int &c){
	if (k>0)
		if(n==1) a--,b++,k--;
		else{
			change(n-1,k,a,c,b);
			change(1,k,a,b,c);
			change(n-1,k,c,b,a);
		}
}
int main(){
	int n,k,a=0,b=0,c=0;
	cin>>n>>k;
	a=n;
	change(n,k,a,b,c);
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
   
