#include <iostream>
#include <math.h>
using namespace std;
long long a[1000000];
long long sum(long long a[],long long i){
	if (i==0) return a[0];
	else return a[i]+sum(a,i-1);
}
long long maxx(long long a[],long long i){
	if (i==0) return a[0];
	else return max(a[i],maxx(a,i-1)); 
}
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	cout<<sum(a,n-1)<<endl;
	cout<<maxx(a,n-1);
	return 0;
}
