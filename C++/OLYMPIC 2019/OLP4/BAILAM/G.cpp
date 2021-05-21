#include <bits/stdc++.h>
using namespace std;
int x[50],d[50],b[50][50];
int n,res=0,dem=0;
void gn(int x[],int n){
		int dem=0;
		if (x[1]==1){
	    for (int i=1;i<n;i++){ 
			if (b[x[i]][x[i+1]]==1 || b[x[i+1]][x[i]]==1) dem++;			
		}
	    if (dem==n-1) res++;
	}
}
void hoanvi(int i,int n,int d[],int x[]){
    for (int j=1;j<=n;j++)
        if (d[j]==0){
            x[i]=j;
            d[j]=1;
            if (i==n) gn(x,n);
			else hoanvi(i+1,n,d,x);
            d[j]=0;
        }
    }
main(){
	int m,h,k;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>h>>k;
		b[h][k]=1;
		b[k][h]=1;
	}
	x[0]=0;
	hoanvi(1,n,d,x);
	cout<<res;
	return 0;
}
