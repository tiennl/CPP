#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
map<ull,ull> M;
ull times (ull a, ull b, ull m){
  	return (ull) a * b % m;
}
ull power(ull val, ull power, ull m){
  	ull res=1,p;
  	for (p=power;p;p=p>>1){
    	if (p & 1) res=times(res, val, m);
    	val = times(val, val, m);
  	}
  	return res;
}
int discrete_log(ull p, ull b, ull n){
	ull i, j, jump;
 	M.clear();
  	jump = (int)sqrt(p);
  	for (i=0; i<jump && i<p-1;i++)
    	M[power(b,i,p)]=i+1;
 	for (i=0;i<p-1;i+=jump){
    	if (j=M[times(n,power(b,p-1-i,p),p)]){
      		j--;
      		return (i+j)%(p-1);
    	}
  	}
  	return -1;
}
int main(){
  	ull p, b, n;
  	int x;
  	while(cin>>p>>b>>n){
    	x=discrete_log(p,b,n);
    	if(x<0) cout<<"no solution"<<endl;
    	else cout<<x<<endl;
  	}
  	return 0;
}

