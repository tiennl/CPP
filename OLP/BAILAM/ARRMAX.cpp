#include <iostream>
#include <math.h>
using namespace std;
long long a[10000000];
int main(){
	long long n,res=0;
	cin>>n;
	cin>>res;
	for (int i=1;i<n;i++){
		cin>>a[i];
		res=max(res,a[i]);
	}
	cout<<res;
	return 0;
}



