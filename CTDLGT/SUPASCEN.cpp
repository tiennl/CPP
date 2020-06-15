#include <iostream>
using namespace std;
unsigned long long a[500],sum[500];
int main(){
	long long n;
	cin>>n;
	if (n<2){
		cout<<"FALSE";
		return 0;
	}
	sum[0]=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		if (i>0 && a[i]<sum[i-1]){
			cout<<"FALSE";
			return 0;
		}
	}
	cout<<"TRUE";
	return 0;
}
