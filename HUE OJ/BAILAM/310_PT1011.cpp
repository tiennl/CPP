#include <iostream>
using namespace std;
int main(){
	long long n,res=0;
	string s;
	cin>>n;
	while (n>0){
		s+=char(n%2+48);
		n/=2;
	}
	for (int i=s.size()-1;i>=0;i--) cout<<s[i];
	return 0;
}
