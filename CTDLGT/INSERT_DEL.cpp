#include <iostream>
using namespace std;
int a[1000000];
void insert(int x, int k, int &n, int a[]){
	for (int i=n+1;i>k;i--) a[i]=a[i-1];
	a[k]=x;
	n++;
}
void del(int k, int &n, int a[]){
	for (int i=k;i<n;i++) a[i]=a[i+1];
	n--;
}
void xuat(int n, int a[]){
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n,x,k;
	cin>>n>>x>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
//	insert(x,k,n,a);
//	xuat(n,a);
	del(k,n,a);
	xuat(n,a);
	return 0;
}



