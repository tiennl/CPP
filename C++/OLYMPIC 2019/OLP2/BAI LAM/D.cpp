#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
bool is_prime(long long x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
int main(){
	long long n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		if (is_prime(i) && a[1]*a[i]!=a[i]){
			cout<<"NO";
			return 0;
		}
		else if (!is_prime(i)){
			for (int j=1;j<=sqrt(i);j++)
				if (i%j==0){
					if (a[i]!=a[j]*a[i/j]){
						cout<<"NO";
						return 0;
					}
				}
		}
	}
	cout<<"YES";
	return 0;
}
