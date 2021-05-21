using namespace std;
#include<bits/stdc++.h>
void NhanhCan(int k, int n, long long &x, long long &y, long long &res, long long &xx ){
 	for(int i=0; i<=9; i++){
 		if (res) return ;
	 	long long rrr = xx- i*pow(10, k) ;
	 	if (rrr<x) continue ;
	 	if (rrr<=y) res = rrr;
	 	if (k>n) NhanhCan(k-1, n, x, y, res,rrr);
	 }
 }
long long discount(long long p, long long q){
		int n  = 0 ;
		long long p1 = p, x= 0, k;
		while(p1) {
			p1/=10;
			n++;
			x =  x*10  +9;
		}
		long long r=0;
		q = p-q;
		for(int i=n-1; i; i--){
				NhanhCan(n-1, i, q, p,r, x);
				if (r) return r;
		}
		return p;
}
int main(){
	cout << discount(2111, 21);
}
