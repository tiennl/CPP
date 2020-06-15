#include <iostream>
using namespace std;
int a[10000];
int find(int x, int n, int a[]){
	for (int i=1;i<=n;i++)
		if (x==a[i]) return i;
	return 0;
}
int main(){
	int n,x;
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<find(x,n,a);
	return 0;
}
