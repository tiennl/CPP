#include <iostream>
using namespace std;
int a[100000];
int search(int x, int n, int a[]){
	int l=1,r=n,i=(l+r)/2;
	while (l!=i && i!=r){
		if (a[i]>x) r=i;
		else if (a[i]<x) l=i;
		else return i;
		i=(l+r)/2;
	}
	return 0;
}
int main(){
	int n,x;
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<search(x,n,a);
	return 0;
}
