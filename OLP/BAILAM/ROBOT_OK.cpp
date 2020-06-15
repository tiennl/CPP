#include <fstream>
using namespace std;
ifstream doc("ROBOT.INP");
ofstream ghi("ROBOT.OUT");
long long n,a,b,k,nf,t,f[1000001];

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
	doc>>t;
	while(t--)
	{
		doc>>n>>a>>b>>k;
		nf=-1;
		Q(1,0);
		long long kq=n-nf-1;
		ghi<<kq<<endl;
	}
	doc.close();
	ghi.close();
	return 0;
}
