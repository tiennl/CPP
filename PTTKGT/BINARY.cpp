#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int binarySearch(int x, int n, int a[]){
	int l=1,r=n,g=(l+r)/2;
	while (l!=g && g!=r){
		if (a[g]>x) r=g;
		else l=g;
		g=(l+r)/2;
	}
	if (a[g]==x) return g;
	else return 0;
}
int main(){
	long long n,x,l,r,g;
	cin>>n>>x;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<binarySearch(x,n,a);
	return 0;
}
