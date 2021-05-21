#include <iostream>
using namespace std;
int x[50],d[50];
void gn(int x[],int n){
		if (x[1]==1){
	    for (int i=1;i<=n;i++){
			cout<<x[i]<<" ";
		}
	    cout<<endl;
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
	int n;
	cin>>n;
	x[0]=0;
	hoanvi(1,n,d,x);
	cout<<d;
}
