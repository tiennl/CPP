#include <bits/stdc++.h>
long long b[10000000];
using namespace std;
int main(){
	long long n,k,num,res=0;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>num;
		if (b[num%k]==0){
			res++;
			b[num%k]=1;
		}
	}
	cout<<res;
	return 0;
}
