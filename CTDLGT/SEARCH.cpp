#include <iostream>
using namespace std;
int a[1000000];
int Search(int x, int n, int a[]){
	int i=0;
	while (i<=n && a[i]!=x) i++;
	if (i>n) return 0;
	else return i;
}
int Find(int x, int l, int r, int a[]){
	if (l>r) return 0;
	else{
		int pivot=(l+r)/2;
		if (x==a[pivot]) return pivot+1;
		else if (x<a[pivot]) return Find(x,l,pivot-1,a);
			  else return Find(x,pivot+1,r,a);
	} 
}
void xuat(int n, int a[]){
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n,x;
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<Search(x,n,a)<<endl;
	cout<<Find(x,1,n,a);
	return 0;
}



