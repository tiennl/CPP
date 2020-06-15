#include <iostream>
using namespace std;
int a[1000000];
void BubbleSort(int n, int a[]){
	for (int i=1;i<n;i++)
		for (int j=n;j>i;j--)
			if (a[j]<a[j-1]) swap(a[j],a[j-1]);
}
void SelectionSort(int n, int a[]){
	for (int i=1;i<=n;i++){
		int minn=a[i],min_pos=i;
		for (int j=i+1;j<=n;j++)
			if (a[j]<minn){
				minn=a[j];
				min_pos=j;
			}
			swap(a[i],a[min_pos]);
	}
}
void QuickSort(int l, int r, int a[]){
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if (l<j) QuickSort(l,j,a);
	if (r>i) QuickSort(i,r,a);
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
	SelectionSort(n,a);
	xuat(n,a);
	QuickSort(1,n,a);
	xuat(n,a);
	return 0;
}



