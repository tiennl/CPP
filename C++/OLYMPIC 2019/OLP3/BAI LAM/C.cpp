#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long sochuso(long long n){
	int so;
	while (n>0){
		so++;
		n/=10;
	}
	return so;
}
unsigned long long ucnn(unsigned long long x,unsigned long long y){
	unsigned long long r=0;
	while (y>0){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main(){
	char ch;
	long long a,b,c,chuki=0,scs=0;
	unsigned long long mau=1,tu=0,so=0;
	cin>>a>>ch>>b>>c;
	scs=sochuso(b);
	if (b==0){
		tu=a;
		mau=1;
	}
	else if (c==0){
		tu=b;
		mau=1;
		for (int i=1;i<=scs;i++)
			mau*=10;
	}
    else if (scs==c){
    	mau=9;
    	for (int i=2;i<=scs;i++)
    		mau=mau*10+9;
    	tu=b;
	}
	else{
		mau=9;
		for (int i=2;i<=c;i++)
			mau=mau*10+9;
		for (int i=1;i<=scs-c;i++)
			mau*=10;
		so=1;
		for (int i=1;i<=c;i++) so*=10;
		chuki=b/so;
		tu=b-chuki;
	}
	if (tu>0 && b!=0) tu=a*mau+tu;
	cout<<tu/ucnn(tu,mau)<<"/"<<mau/ucnn(tu,mau);
	return 0;
}
