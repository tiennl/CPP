#include <iostream>
#include <fstream>
using namespace std;
int a[100];
int b[100];
int vt[100];
void sorta(int l, int r,int a[],int vt[]){
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
    if (l<j) sorta(l,j,a,vt);
    if (r>i) sorta(i,r,a,vt);
}
void sortvt(int l, int r,int vt[],int b[]){
	int pivot=vt[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (vt[i]<pivot) i++;
		while (vt[j]>pivot) j--;
		if (i<=j){
			swap(vt[i],vt[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
    if (l<j) sortvt(l,j,vt,b);
    if (r>i) sortvt(i,r,vt,b);
}
main(){
	ifstream fi ("museq.inp");
	ofstream fo ("museq.out");
	int t,n;
	fi>>t;
	for (int i=0;i<t;i++){
		fi>>n;
		for (int j=0;j<n;j++) fi>>a[j];
		for (int j=0;j<n;j++) vt[j]=j;
		sorta(0,n-1,a,vt);
		b[0]=1;
		for (int j=1;j<n;j++){
			if (a[j]==a[j-1]) b[j]=b[j-1];
			if (a[j-1]<a[j]) b[j]=b[j-1]+1;
		}
		sortvt(0,n-1,vt,b);
		for (int j=0;j<n;j++) fo<<b[j]<<" ";
		fo<<endl;
	}
	fi.close();
	fo.close();
}


	



