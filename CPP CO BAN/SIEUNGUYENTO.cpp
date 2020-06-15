#include <iostream>
#include <math.h>
using namespace std;
bool snt(int x){
	if (x<2) return false;
	if (x==2) return true;
	if (x>2){
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0){
			return false;
			break;
		}
	return true;
    } 
}
bool kt(int y,int m){
	int k=0;
	if (y>9){
	while (y>0){
		if (snt(y)==true) k++;
		y/=10;
	}
	if (k==m) return true;
	else return false;
	}
	if (y<10 && snt(y)==true ) return true;
	else return false;
}

int main(){
	int n,s1,s2,d,j;
	cin>>n;
	s1=1;
	s2=1;
	d=0;
	for (int i=0;i<n-1;i++) s1*=10;
	s2=s1*10-1;
//	cout<<s1<<" "<<s2<<endl;
	for (int i=s1;i<=s2;i++){
		j=i;
		if (kt(j,n)) {
		 d++;
	}}
	cout<<d;
}

