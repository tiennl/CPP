#include <iostream>
#include <math.h>
using namespace std;
long long a[300000];
long long vt[300000];
long long x[4];
long long y[4];
void sort(int l, int r,long long a[]){
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			swap(vt[i],vt[j]);
			i++;
			j--;
		}
	}
    if (l<j) sort(l,j,a);
    if (r>i) sort(i,r,a);
}
main(){
    int n,d,b,c;
    cin>>n>>d>>b>>c;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) vt[i]=i;
    sort(0,n-1,a);
    x[0]=vt[n-3];x[1]=vt[n-2];x[2]=vt[n-1];
    y[0]=a[n-3];y[1]=a[n-2];y[2]=a[n-1];
    for (int i=0;i<2;i++)
        for (int j=i+1;j<3;j++)
            if (x[i]>x[j]){
                swap(x[i],x[j]);
                swap(y[i],y[j]);
            }
    cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[0]*d+y[1]*b+y[2]*c<<endl;
    x[0]=vt[0];x[1]=vt[1];x[2]=vt[2];
    y[0]=a[0]; y[1]=a[1]; y[2]=a[2];
    for (int i=0;i<2;i++)
        for (int j=i+1;j<3;j++)
            if (x[i]>x[j]){
                swap(x[i],x[j]);
                swap(y[i],y[j]);
            }
    cout<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[0]*d+y[1]*b+y[2]*c;
 
            
    
}