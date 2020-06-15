#include <iostream>
using namespace std;
main(){
	int n1,n2,tong=0;
	cin>>n1>>n2;
	for (int i=n1;i<=n2;i++)
		if (i%2==0) tong+=i;
	cout<<tong;
}
