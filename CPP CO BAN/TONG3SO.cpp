#include <iostream>
using namespace std;
int main(){
	int n,s;
	s=0;
	cin>>n;
	while (n>0){
		s+=(n%10);
		n/=10;
	}
	cout<<s;
}
