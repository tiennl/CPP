#include <iostream>
using namespace std;
int UCLN(int a, int b){
	while (a!=b){
		if (a>b) a-=b;
		else if (a<b) b-=a;
		else return a;
	}
	return a;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<UCLN(a,b);
	return 0;
}
