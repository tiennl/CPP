#include <iostream>
using namespace std;
void HaNoiTown(int n, char A, char B, char C){
	if (n==1)
		cout<<"Chuyen dia tu coc "<<A<<" sang coc "<<C<<endl;
	else{
		HaNoiTown(n-1,A,C,B);
		HaNoiTown(1,A,B,C);
		HaNoiTown(n-1,B,A,C);
	}
}
int main(){
	int n;
	char A='A',B='B',C='C';
	cin>>n;
	HaNoiTown(n,A,B,C);	
	return 0;
}
