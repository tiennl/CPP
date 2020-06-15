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
	int n;
	cin>>n;
	if (uoc(n,sodao(n))) cout<<"than thien";
	else cout<<"khong than thien";
}
