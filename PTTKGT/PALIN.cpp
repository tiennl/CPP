#include <iostream>
using namespace std;
int a[1000000];
bool isPalin(int l, int r){
	if (l<r){
		if (a[l]!=a[r]) return 0;
		else return isPalin(l+1,r-1);
	}
	return 1;
}
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (isPalin(0,n-1)) cout<<"Mang doi xung";
	else cout<<"Mang khong doi xung";
	return 0;
}
