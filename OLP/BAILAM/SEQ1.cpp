#include <fstream>
long long a[10000000];
using namespace std;
main(){
	ifstream fi("seq.inp");
	ofstream fo("seq.out");
	int n,i,l,r,sl,sr,dl,dr,max;
	max=-10000000;
	fi>>n;
	for (i=0;i<n;i++) fi>>a[i];
	for (i=2;i<n-3;i++){
		sl=0;
		sr=0;
		dl=0;
		dr=0;
		for (l=0;l<=i;l++){
			if (l%3!=0){
				dl++;
				sl+=a[l];
			}	
			else if (dl%3==0 && dl>0){
				for (r=i+1;r<n;r++){
					if (r%3!=0){
						dr++;
						sr+=a[r];
					}
					else{
						fo<<i<<" "<<dl<<" "<<dr<<" "<<sl<<" "<<sr<<" "<<endl;
						if (sl+sr>max) max=sl+sr;
					}
				}
			}
		}
	}
	fo<<max;
	fi.close();
	fo.close();
}
