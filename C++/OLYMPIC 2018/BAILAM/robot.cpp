#include <fstream>
using namespace std;
long long n,a,b,k,nf,t,f[1000001];
ifstream fi("robot.inp");
ofstream fo("robot.out");
bool find(long long x)
{
	for(long i=0;i<nf;i++) if(x==f[i]) return true;
	return false;
}

void Q(long long u, long long v){
	nf++;
	f[nf]=u;
	if(v>=k) return;
	if(u+a<=n&&!find(u+a)) Q(u+a,v+1);
	if(u-b>=1&&!find(u-b)) Q(u-b,v+1);
}
int main(){
	fi>>t;
	while(t--)
	{
		fi>>n>>a>>b>>k;
		nf=-1;
		Q(1,0);
		long long kq=n-nf-1;
		fo<<kq<<endl;
	}
	fi.close();
	fo.close();
	return 0;
}
