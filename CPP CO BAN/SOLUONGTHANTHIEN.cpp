#include <iostream>
using namespace std;
bool uoc(int y,int k){
	int r;
	while (k>0){
		r=y%k;
		y=k;
		k=r;
	}
	if (y==1) return true;
	else return false;
}
int sodao(int x){
	int s=0;
	while (x>0){
		s=s*10+(x%10);
		x/=10;
	}
	return s;
}
int main(){
	int a,b,d;
	d=0;
	cin>>a>>b;
	for (int i=a;i<=b;i++)
		if (uoc(i,sodao(i))) d++;
	cout<<d;
	
}
