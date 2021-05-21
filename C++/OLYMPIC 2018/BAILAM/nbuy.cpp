#include <iostream>
#include <math.h>
using namespace std;
long long m[100];
long long gia[100];
long long lech[100];
void sort(int l, int r,long long lech[],long long m[],long long gia[]){
	int pivot=lech[(l+r)/2];
	int i=l,j=r;
	while (i<j){
		while (lech[i]<pivot) i++;
		while (lech[j]>pivot) j--;
		if (i<=j){
			swap(lech[i],lech[j]);
			swap(m[i],m[j]);
			swap(gia[i],gia[j]);
			i++;
			j--;
		}
	}
    if (l<j) sort(l,j,lech,m,gia);
    if (r>i) sort(i,r,lech,m,gia);
}
main(){
    int n,x;
    cin>>n>>x;
    long long s=0;
    for (int i=0;i<n;i++){
        cin>>m[i]>>gia[i];
        lech[i]=m[i]-gia[i];
    }
    sort(0,n-1,lech,m,gia);
    int i=n;
    while (x>0){
        i--;
        s=s+(x/m[i])*gia[i];
        x%=m[i];
    }
    cout<<s;
}