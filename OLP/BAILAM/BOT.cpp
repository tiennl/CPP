#include <fstream>
using namespace std;
long long a[1000000],s[1000000],maxx[1000000],vtri[1000000];
main(){
	ifstream fi("bot.inp");
	ofstream fo("bot.out");
	long long n,res,v1,v2;
	fi>>n;
	for (int i=0;i<n;i++){
		fi>>a[i];
		s[i]=s[i-1]+a[i];
	}
	maxx[n-1]=s[n-1];
	vtri[n-1]=n;
	for (int i=n-2;i>=0;i--){
		if (s[i]>maxx[i+1]){
			maxx[i]=s[i];
			vtri[i]=i+1;
		}
		else{
			maxx[i]=maxx[i+1];
			vtri[i]=vtri[i+1];
		}
	}
	res=a[0];v1=0;v2=0;
	if (s[n-1]>res){
		res=s[n-1];
		v1=1;
		v2=n;
	}
	s[-2]=1000000000;
	s[-1]=1000000000;
	maxx[-1]=-1000000000;
	for (int i=-2;i<n;i++){
		if (maxx[i+1]-s[i]>res){
			res=maxx[i+1]-s[i];
			v1=i+2;
			v2=vtri[i+1];
		}
	}
	fo<<v1<<" "<<v2<<" "<<res<<endl;
	fi.close();
	fo.close();
}
