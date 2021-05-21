#include <iostream>
#include <fstream>
using namespace std;
main(){
	ifstream fi ("leapyear.inp");
	ofstream fo ("leapyear.out");
	int a,b,d;
	fi>>a>>b;
	d=0;
	for (int i=0;i<=1000;i++)
		if ((i%19==0 || i%19==3 || i%19==6 || i%19==9 || i%19==11 || i%19==14 || i%19==17) && i>2) d++;
	fo<<d;
	fi.close();
	fo.close();
}
