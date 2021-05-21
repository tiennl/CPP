#include <iostream>
#include <math.h>
using namespace std;
bool snt(long long a){
	if (a<2){
		return false;
	}
	else if (a>2){
		if (a%2==0){
			return false;
		}
		for (int ii=2; ii<=sqrt(a); ii++){
			if (a%ii==0){
				return false;
			}
		}
	}
	return true;
}
long long ucln(long long a,long long b){
    long long r;
    while (b>0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
main(){
    long long n,dem;
    cin>>n;
    dem=0;
    if (snt(n)) cout<<n-1;
    else{
        for (int i=1;i<n;i++)
            if (ucln(i,n)==1)dem++;
        cout<<dem;
    }
    
}