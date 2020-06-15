#include <iostream>
using namespace std;
int main(){
	int m,n,g=0,t=0;
	cin>>m>>n;
	t=(n-2*m)/2;
	g=m-t;
	if(g<0 || t<0 || n%2!=0)
		cout<<-1;
	else cout<<g<<" "<<t;
	return 0;
}
