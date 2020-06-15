#include <iostream>
#include <algorithm>
using namespace std;
long long a[100000],c[100000],d[100000],kq[100000];
long long b[10000][10000];
bool uoc(long long x,long long y){
	long long r;
	while (y>0){
		r=x%y;
		x=y;
		y=r;
	}
	if (x==1) return true;
	return false;
}
main(){
	unsigned long long mul,t;
	long long n,d1,d2,max;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
/*	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (uoc(a[i],a[j])) b[i][j]=1;
			else b[i][j]=0;*/
	d2=0;
	max=0;
	mul=100000000000000000;
	for (int i=0;i<n-1;i++){
		d2=1;
		c[0]=a[i];
		d[0]=i;
		for (int j=i+1;j<n;j++){
			if (uoc(a[i],a[j])){
				d1=0;
				for (int k=0;k<d2;k++)
					if (uoc(a[j],a[d[k]])) d1++;
					else break;
				if (d1==d2){
					d2++;
					c[d2-1]=a[j];
					d[d2-1]=j;
				}
			} 
	    }
	//  for (int ii=0;ii<d2;ii++) cout<<c[ii]<<" ";
    //  cout<<endl;
	 	if (d2>max){
				max=d2;
				for (int j=0;j<d2;j++) kq[j]=c[j];
			}	
			if (d2==max){
				t=1;
				for (int j=0;j<d2;j++) t*=c[j];
				if (t<mul){
					max=d2;
					mul=t;
					for (int j=0;j<d2;j++) kq[j]=c[j];
				} 
			}	
		}
	sort(kq,kq+max);
	if (max>1){
		cout<<max<<endl;
		for (int i=0;i<max;i++) cout<<kq[i]<<" ";
	}
	else cout<<"-1";
}
