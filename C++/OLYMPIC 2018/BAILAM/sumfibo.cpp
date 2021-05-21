#include <iostream>
using namespace std;
main(){
	long long n,a1,a2,a3;
	unsigned long long s;
	cin>>n;
	a1=1;
	a2=1;
	s=2;
	if (n==1 || n==2) cout<<n;
	else{
		for (int i=3;i<=n;i++){
		a3=a1+a2;
		s+=a3;
		a1=a2;
		a2=a3;
		if (s>13) s%=13; 
		cout<<s<<" ";
		}
		cout<<s%13;
	}
}
//	1	1	2	3	5	8	13	 21	  34	55	 89	  144	233   377
//  1	2	4	7	12	20	33	 54	  88	143  232  376	609	  986
//  1   2 	4	7	12	7	7	 2	  10	0	 11	   12	11	  11 
