#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool doixung(string x){
	for (int i=0;i<x.size()/2;i++){
		if (x[i]!=x[x.size()-i-1]) return false;
	}
	return true;
}
main(){
	string s,s1;
	int q,max,l,d;
	ifstream fi ("palin.inp");
	ofstream fo ("palin.out");
	fi>>s;
	fi>>q;
	max=0;
	for (int i=0;i<q;i++){
		fi>>l;
		if ((l==1 || l==0) && s.size()>=1) fo<<"1"<<endl;
		else{
			d=0;
			for (int j=0;j<=s.size()-l;j++){
				s1=s.substr(j,l);
				if (doixung(s1)==true){
					d=1;
					fo<<"1"<<endl;
					break;
				}
			}
			if (d==0) fo<<"0"<<endl;
		}
	}
	fi.close();
	fo.close();
}
