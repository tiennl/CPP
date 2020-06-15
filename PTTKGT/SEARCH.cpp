#include <iostream>
using namespace std;
int a[1000000],x,n;
int Find(int l, int r){
	if (l>r) return 0;
	else{
		int pivot=(l+r)/2;
		if (x==a[pivot]) return pivot;
		else if (x<a[pivot]) return Find(l,pivot-1);
			else return Find(pivot+1,r);
	} 
}
int main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<Find(1,n);
	return 0;
}
