#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
long long a[10000][10000];
int b[10000][10000];
bool snt(long long aa){
	if (aa<2){
		return false;
	}
	else if (aa>2){
		if (aa%2==0){
			return false;
		}
		for (int ii=2;ii<=sqrt(aa);ii++){
			if (aa%ii==0){
				return false;
			}
		}
	}
	return true;
}
main(){
	ifstream fi ("primetab.inp");
	ofstream fo ("primetab.out");
	long long m,n,q,x,y,r,c,kt,d;
	fi>>m>>n>>q;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++){
			fi>>a[i][j];
			if (snt(a[i][j])) b[i][j]=1;
			else b[i][j]=0;
		}
	for (int i=0;i<q;i++){
		fi>>x>>y>>r>>c;
		kt=0;
		for (int j=x;j<=y-r+1;j++){
			for (int jj=1;jj<=n-c+1;jj++){
				d=0;
				for (int k=j;k<=j+r-1;k++)
					for (int kk=jj;kk<=jj+c-1;kk++)
						if (b[k][kk]==1) d++;
						else break;
				if (d==r*c){
					kt=1;
					break;
				}
			}
			if (kt==1) break;
	    }
	    if (kt==1) fo<<"1"<<endl;
	    else fo<<"0"<<endl;
	}    
//	fo<<"1";
	fi.close();
	fo.close();
}


