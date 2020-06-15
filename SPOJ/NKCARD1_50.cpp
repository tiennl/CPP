#include <iostream>
#include <string>
using namespace std;
long long a[1000000];
main(){
	long long m,k,temp;
	string s;
	cin>>m>>k;
	getline(cin,s);
	for (int i=0;i<m;i++) a[i]=i;
	for (int i=0;i<s.size();i++){
		if (s[i]=='A'){
			temp=a[0];
			for (int j=0;j<m;j++) a[j]=a[j+1];
			a[m-1]=temp;
		}
		else
		if (s[i]=='B'){
			temp=a[1];
			for (int j=1;j<m;j++) a[j]=a[j+1];
			a[m-1]=temp;
		}
	}
	cout<<a[k-1]<<" "<<a[k]<<" "<<a[k+1];
}
