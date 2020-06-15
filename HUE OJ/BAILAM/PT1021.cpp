#include <bits/stdc++.h>
long long a[1000000];
using namespace std;
long long sum(long long n){
	long long res=0;
	while (n>0){
		res+=((n%10)*(n%10));
		n/=10;
	}
	return res;
}
int main(){
	long long n,num,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		num=i;
		while (num>1 && a[num]!=i){
			num=sum(num);
			a[num]=i;
		}
		if (num==1) ans++;
		if (num==1) cout<<i<<endl;
	}
	cout<<ans;
	return 0;
}

