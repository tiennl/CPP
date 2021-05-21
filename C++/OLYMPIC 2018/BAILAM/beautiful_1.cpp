#include <iostream>
using namespace std;
int x[500];
long long a[100000],kq[100000];
int dem=0,d=0;
bool uoc(long long a1,long long a2){
	long long r;
	while (a2>0){
		r=a1%a2;
		a1=a2;
		a2=r;
	}
	if (a1==1) return true;
	return false;
}
void nghiem(int x[],int k){
	dem=0;
	t=1;
	    for (int i=1;i<=k-1;i++)
			for (int j=i+1;j<=k;j++)
				if (b[a[x[i]]][a[x[j]]]==1) dem++;
		if (dem==k && dem>max) {
			max=dem;
			for (int i=0;i<dem;i++){
				kq[i]=a[x[i]];
				t*=a[i];
		}
		if (dem==k && dem>max && t<mul ){
			for (int i=0;i<dem;i++) kq[i]=a[x[i]];
		}
}
void tohop(int i,int n,int k){
	int j;
	for (j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if (i==k) nghiem(x,k);
		else tohop(i+1,n,k);
	}
}
main(){
	int n,k;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (uoc(a[i],a[j])) b[i][j]=1;
			else b[i][j]=0;
	x[0]=0;
	umul=1000000000;
	for (int k=2;k<=n;k++) tohop(1,n,k);
	
}
