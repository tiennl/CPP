#include <bits/stdc++.h>
using namespace std;
int x[100];
int k,n;
void pf(){
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<endl;
}
void permu(int i){
	for (int j=1;j<=k;j++){
		x[i]=j;
		if (i==n) pf();
		else permu(i+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>k>>n;
	cout<<pow(k,n)<<endl;
	permu(1);
	return 0;
}
