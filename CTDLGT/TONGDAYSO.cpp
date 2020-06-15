#include <iostream>
#include <math.h>
using namespace std;
double S1(double n){
	if (n==0) return 0;
	else return n+S1(n-1); 
}
double S2(double n){
	if (n==0) return 0;
	else return 1/n+S2(n-1);
}
double S3(double n){
	if (n==0) return 0;
	else return pow(-1,n+1)*(1/n)+S3(n-1);
}
double S4(double n, double x){
	if (n==0) return 1;
	else return pow(sin(x),n)+S4(n-1,x);
}
int main(){
	double n,x;
	cin>>n>>x;
	//	DE QUY
	cout<<S1(n)<<endl;	
	cout<<S2(n)<<endl;
	cout<<S3(n)<<endl;
	cout<<S4(n,x)<<endl;
	//	KHONG DE QUY
	double res=0;
	for (double i=1;i<=n;i++) res+=i;
	cout<<res<<endl;
	res=0;
	for (double i=1;i<=n;i++) res+=1/i;
	cout<<res<<endl;
	res=0;
	for (double i=1;i<=n;i++) res+=pow(-1,i+1)*(1/i);
	cout<<res<<endl;
	res=0;
	for (int i=1;i<=n;i++) res+=pow(sin(x),i);
	res+=1;
	cout<<res;
	return 0;
}



















