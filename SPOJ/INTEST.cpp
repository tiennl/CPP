#include <iostream>
using namespace std;
main(){
	int n,num,k,count=0;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>num;
		if (num%k==0) count++;
	}
	cout<<count;
}
