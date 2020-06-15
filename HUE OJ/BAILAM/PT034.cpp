#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull unsigned long long 
#define N 1000005

int main(){
	FIO
	ull n,num,res=0;
	cin>>n;	
	while (n--){
		cin>>num;
		res+=pow(num/10,num%10);
	}
	cout<<res;
	return 0;
}
