#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int a[100000];
int b[100000];
int k[100000];
ifstream fi ("scard.inp");
ofstream fo ("scard.out");
bool snt(int x){	
	if (x<2){
		return false;
	}
	else if (x>2){
		if (x%2==0){
			return false;
		}
		for (int ii=2;ii<=sqrt(x);ii++){
			if (x%ii==0){
				return false;
			}
		}
	}
	return true;
}
main(){
	int n,dem,j,m,d,k1,max;
	fi>>m>>n;
	max=0;
	for (int i=0;i<m;i++){
		fi>>k[i];
		if (k[i]>max) max=k[i];
	}
	for (int i=2;i<=max;i++)
	 	if (snt(i)==true){
	 		d++;
	 		a[d]=i;
		} 
	for (int i=0;i<m;i++){
		if (snt(k[i])==true) b[i]++;
		else 
		if (k[i]>2){
			j=k[i];
			k1=1; 
			while (j>1){
				if (j%a[k1]==0){
					b[a[k1]]++;
					j/=a[k1];
					if (j==0) break;
				}
				else k1++;
			}
		} 
	}
	for (int i=0;i<=d;i++) fo<<a[i]<<" "<<b[a[i]]<<endl;
	fi.close();
	fo.close();
}
