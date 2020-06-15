#include <iostream>
using namespace std;
long long a[1000000];
int main(){
	long long n,res=0;
	cin>>n;
	cin>>res;
	for (int i=1;i<n;i++){
		cin>>a[i];
		if (a[i]>res) res=a[i];
	}
	cout<<res;
	return 0;
}



