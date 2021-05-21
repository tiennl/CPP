#include <iostream>
using namespace std;
int a[100000];
main(){
	int i=-1;
	while (!ceof()){
		i++;
		cin>>a[i];
	}
	for (int j=0;j<i;j++) cout<<a[j]<<" ";
}
