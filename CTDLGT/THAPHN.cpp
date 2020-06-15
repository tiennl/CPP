#include <iostream>
using namespace std;
void ThapHN(int n, char A, char B, char C){
	if (n==1) cout<<"Chuyen dia tu "<<A<<" qua "<<C<<endl;
	else{
		ThapHN(n-1,A,C,B);
		ThapHN(1,A,B,C);
		ThapHN(n-1,B,A,C);
	}
}
int main(){
	int n;
	cin>>n;
	ThapHN(n,'A','B','C');
	return 0;
}
