#include <iostream>
using namespace std;
int a[1000000];
void BubbleSort(int n, int a[]){
	for (int i=1;i<n;i++)
		for (int j=n;j>i;j--)
			if (a[j]<a[j-1]) swap(a[j],a[j-1]);
}
void xuat(int n, int a[]){
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	BubbleSort(n,a);
	xuat(n,a);
	return 0;
}



