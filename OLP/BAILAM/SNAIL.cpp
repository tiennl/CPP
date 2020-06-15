#include <iostream>
using namespace std;
main(){
	int a,b,v;
	cin>>a>>b>>v;
	if (a>=v){
		cout<<1;
		return 0;
	}
	int kq=(v-b)/(a-b);
	if ((v-b)%(a-b) != 0) kq++;
	cout<<kq;
	return 0;
}
