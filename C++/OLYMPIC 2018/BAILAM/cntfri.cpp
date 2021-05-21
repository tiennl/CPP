#include <fstream>
using namespace std;
string a[1000000];
main(){
	ifstream fi("cntfri.inp");
	ofstream fo("cntfri.out");
	int n,i,j,k;
	long long dem=0;
	fi>>n;
	for (i=0;i<n;i++) fi>>a[i];
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			for (k=0;k<a[i].size();k++)
				if (a[j].find(a[i][k])>0){
					dem++;
					fo<<dem<<" "<<a[i]<<" "<<a[j]<<endl;
					break;
				}
	fo<<dem;
	fi.close();
	fo.close();
}
