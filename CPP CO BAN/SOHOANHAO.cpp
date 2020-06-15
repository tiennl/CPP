#include <iostream>
using namespace std;
bool kt(int x){
	int s=0;
	for (int i=1;i<x;i++)
		if (x%i==0) s+=i;
	if (s==x) return true;
	else return false;
}
main(){
	int n;
	cin>>n;
	if (kt(n)) cout<<"So hoan hao";
	else cout<<"So khong hoan hao";
}
