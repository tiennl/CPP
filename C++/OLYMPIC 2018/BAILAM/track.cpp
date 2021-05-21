#include <fstream>
using namespace std;
long long a[10000000];
unsigned long long s[10000000];
int find(unsigned long long s[],long long n,long long x){
	int l=0;
	int r=n-1;
	int g=(l+r)/2;
	while (g!=l && g!=r){
		if (s[g]>=x) r=g;
		else l=g;
		g=(l+r)/2;
	}
	for (int g=r;g>=l;g--)
		if (s[g]<=x){
			return g;
			break;
		}
	return -1;	
}
main(){
	ifstream fi ("track.inp");
	ofstream fo ("track.out");
	long long n,t,x,k,res=0;
	fi>>n>>t;
	for (int i=0;i<n;i++){
		fi>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for (int i=0;i<n;i++){
		x=t+s[i]-a[i];
		k=find(s,n,x);
		if (k>=0) res+=(k-i+1);
	}
	fo<<res;
	fi.close();
	fo.close();
}
