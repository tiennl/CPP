#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
bool is_prime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
long long uoc_min(long long x){
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return i;
	return 0;
}
bool check(long long x){
	long long multi=1,y=x;
	while (x>0){
		multi*=(x%10);
		x/=10;
	}
	if (multi==y) return true;
	else return false;
}
int main(){
	long long n,k=-1,so=0;

	cin>>n;
	if (n==0) cout<<10;
	else if (n>=1 && n<=9) cout<<n;
	else if (!is_prime(n) && uoc_min(n)>9) cout<<-1;
	else if (is_prime(n)){
		if (check(n)) cout<<n;
		else cout<<-1;
		return 0;
	}
	else{
		so=9;
		k=-1;
		while (n>1){
			if (n%so==0){
				k++;
				a[k]=so;
				n/=so;
				if (!is_prime(n) && uoc_min(n)>9){
					cout<<-1;
					return 0;
				}
				else if (is_prime(n) && n>9){
					if (check(n)){
						k++;
						a[k]=n;
					}
				    else cout<<-1;
					return 0;
				//	break;
				}
			}
			else so--;
		}
		for (int i=k;i>=0;i--) cout<<a[i];
	}
	return 0;
}
