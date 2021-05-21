#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define N 1000
string a[N];
int main(){
	string n,k;
	ll kt,dem,s,kk;
	getline(cin,n);
	ll d=0;
	a[0]=n;
	for (int i=0;i<n.size();i++){
		k=n;
		for (int j=1;j<n.size()-i+1;j++){
			k=n;
			k.erase(i,j);
			while (k[0]=='0' && k.size()>1) k.erase(0,1);
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
	dem=0;
	for (int i=0;i<=d;i++){
		k=a[i];
		s=0;
		if (k.size()==1 && k[0]=='0') dem++;
		for (int j=0;j<k.size();j++){
			kk=(int)k[j]-48;
			s+=kk;
		}
		if (s>0 && s%3==0) dem++;
	} 
	cout<<dem;
	return 0;
}
