#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
string a[10000000];
main(){
	ifstream fi ("numset.inp");
	ofstream fo ("numset.out");
	string n,k;
	int kt,dem,s,kk;
	getline(fi,n);
	long long d=-1;
	for (int i=0;i<n.size();i++){
		k=n;
		for (int j=1;j<n.size()-i+1;j++){
			k=n;
			k.erase(i,j);
			while (k[0]=='0') k.erase(0,1);
			kt=0;
			for (int jj=0;jj<=d;jj++)
				if (k==a[jj]){
					kt=1;
					break;
				}
			if (kt==0){
				d++;
				a[d]=k;
			}
				
		} 
	}
	for (int i=0;i<=d;i++){
		k=a[i];
		s=0;
		for (int j=0;k.size();j++){
			kk=(int)k[j];
			s+=kk;
		}
		if (s%3==0) dem++;
	}
	fo<<dem;
	fi.close();
	fo.close();
}
