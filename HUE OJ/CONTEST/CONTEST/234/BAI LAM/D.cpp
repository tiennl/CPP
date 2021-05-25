#include <bits/stdc++.h>
using namespace std;
int x[100];
void kt(int n, int x[]){
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<endl;
}
void hv(int i, int n, int x[]){
	for (int j=0;j<2;j++){
		x[i]=j;
		if (i==n) kt(n,x);
		else hv(i+1,n,x);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	hv(1,n,x);
	return 0;
}
