#include <stdio.h>
using namespace std;
main(){
	long long t,a,b,d12,d30,d60,result;
	scanf("%d",&t);
	for (long long i=0;i<t;i++){
		scanf("%d%d",&a,&b);
		d12=0;
		d30=0;
		d60=0;
		for (long long j=a;j<=b;j++){
			printf("%d",j);
			if (j%12==0) d12++;
			if (j%30==0) d30++;
			if (j%60==0) d60++;
		}
//		printf("%d",d12+d30-2*d60);
	}
	return 0;
}
