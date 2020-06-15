#include <iostream>
using namespace std;
int x[50];
int dem=-1;
void nghiem(int x[],int k,int m){
	dem++;
	if (dem==m)
	    for (int i=1;i<=k;i++) cout<<x[i]<<" ";
	    //cout<<endl;
}
void tohop(int i,int n,int k,int m){
	int j;
	for (j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if (i==k) nghiem(x,k,m);
		else tohop(i+1,n,k,m);
	}
}
main(){
	int n,k,m;
	cin>>n>>k>>m;
	x[0]=0;
	tohop(1,n,k,m);
}
