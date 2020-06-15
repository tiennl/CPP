#include <bits/stdc++.h>
using namespace std;
long long reverse(long long x){
	long long ans=0;
	while (x>0){
		ans=ans*10+(x%10);
		x/=10;
	}
	return ans;	
}
bool palindrome(long long x){
	if (x==reverse(x)) return true;
	return false;
}
int main(){
	long long n,num;
	cin>>n;
	while (n--){
		cin>>num;
		if (palindrome(num)) cout<<num<<" ";
	}
	return 0;
}
