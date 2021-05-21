#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
long long a[1000];
long long b[1000];
long long c[1000];
long long d[1000];
void sorta(int l, int r,long long a[],long long b[],long long c[],long long d[]){
	int pivot=a[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(c[i],c[j]);
			swap(d[i],d[j]);
			i++;
			j--;
		}
	}
    if (l<j) sorta(l,j,a,b,c,d);
    if (r>i) sorta(i,r,a,b,c,d);
}
void sortb(int l, int r,long long a[],long long b[],long long c[],long long d[]){
	int pivot=b[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (b[i]<pivot) i++;
		while (b[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(c[i],c[j]);
			swap(d[i],d[j]);
			i++;
			j--;
		}
	}
    if (l<j) sortb(l,j,a,b,c,d);
    if (r>i) sortb(i,r,a,b,c,d);
}
main(){
	int n,t1,t2,t3,t4,d1,d2,d3,v1,v2,so,temp;
	ifstream fi ("svoi.inp");
	ofstream fo ("svoi.out");
	fi>>n>>t1>>t2;
	t3=t1;
	t4=t2;
	for (int i=0;i<n;i++){
		fi>>a[i]>>b[i]>>c[i]>>d[i];
	}
	d1=0;
	d2=0;
	d3=0;
	sorta(0,n-1,a,b,c,d);
	int i=0;
	while (i<n){
		so=a[i];
		v1=i;  
		v2=i;
		for (int j=i+1;j<n;j++)
			if (a[j]==so) v2=j;
			else break;
				for (int j1=v1;j1<=v2-1;j1++)
					for (int jj=j1+1;jj<=v2;jj++)
						if (b[j1]>b[jj]){
	//						fo<<b[j1]<<" "<<b[jj]<<endl;
							swap(b[j1],b[jj]);
							swap(c[j1],c[jj]);
							swap(d[j1],d[jj]);
						}		
		i+=(v2-v1+1);
	}		
	//-----------------------------------
	for (int i=0;i<n;i++){
	 	if (a[i]<=t1 && b[i]<=t2){
	 		t1+=c[i];
	 		t2+=d[i];
			d1++;	
		}
		if (a[i]>t1 || b[i]>t2) break;
	}
	if (d1>d3) d3=d1;  
//	for (int i=0;i<n;i++) fo<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
//	fo<<endl; 
	//----------------------------------------  
	sortb(0,n-1,a,b,c,d);
	i=0;
	while (i<n){
		so=b[i];
		v1=i;  
		v2=i;
		for (int j=i+1;j<n;j++)
			if (b[j]==so) v2=j;
			else break;
//				fo<<v1<<" "<<v2<<endl;
				for (int j1=v1;j1<=v2-1;j1++)
					for (int jj=j1+1;jj<=v2;jj++)
						if (a[j1]>a[jj]){
//							fo<<b[j1]<<" "<<b[jj]<<endl;
							swap(a[j1],a[jj]);
							swap(c[j1],c[jj]);
							swap(d[j1],d[jj]);
						}
		i+=(v2-v1+1);
	}		
	for (int i=0;i<n;i++){
	 	if (a[i]<=t3 && b[i]<=t4){
	 		t3+=c[i];
	 		t4+=d[i];
			d2++;	
		}
		if (a[i]>t3 || b[i]>t4) break;
	}
	if (d2>d3) d3=d2; 
	fo<<d3;
	fi.close();
	fo.close();
}

