#include <fstream>
using namespace std;
long long a[1000000];
int b[1000000][10];
main(){
	ifstream fi("cntfri.inp");
	ofstream fo("cntfri.out");
	int n,i,j,k,dem,kt;
	fi>>n;
	for (i=0;i<n;i++)
		for (j=0;j<10;j++) b[i][j]=0;
	for (i=0;i<n;i++){
		fi>>a[i];
		k=a[i];
		while (k>0){
			b[i][k%10]++;
			k/=10;
		}
	}
	dem=0;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			for (k=0;k<10;k++)
				if (b[i][k]>0 && b[j][k]>0){
					dem++;
					kt=1;
					break;
				}
	fo<<dem;
	fi.close();
	fo.close();
}
