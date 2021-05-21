#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
using namespace std;
#define k 1000000007
long long sum(long long s){
	long long ss,s1,s2,s3;
	s1=2*s+1; 
	s2=s+1; 
	s3=s;
	if (s3%2==0) s3/=2; 
	else s2/=2;
	if (s3%3==0) s3/=3;
	else{
		if (s2%3==0) s2/=3;
		else s1/=3;
	}
	ss=(s2*s3)%k;
	ss=(ss*s1)%k;
	return ss;
}
int main(){
	ifstream fi ("sum.inp");
    ofstream fo ("sum.out");
    double a,b;
    long long t1,t2;
    fi>>a>>b;
    long long n=a,m=b;
	if(n==a) n--;
    t1=sum(n);
    t2=sum(m);
    if (t2-t1>=0) fo<<t2-t1;
	else fo<<t2-t1+k;
    fi.close();
    fo.close();
}
//tong binh phuong cac so tu nhien tu 1 toi n: n(n+1)(2n+1)/6
