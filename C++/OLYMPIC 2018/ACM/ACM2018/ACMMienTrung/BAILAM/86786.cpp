#include <iostream>
#include <math.h>
using namespace std;
long long a[1000000];
int main(){
	long long n,maxx;
 	cin>>n;
	maxx=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			if (abs(a[i]-a[j])+abs(i-j)>maxx) maxx=abs(a[i]-a[j])+abs(i-j);
		}
	cout<<maxx;
	return 0;
}
